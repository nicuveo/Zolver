//
// game.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <iomanip>
#include <iostream>
#include "options.hh"
#include "game.hh"
#include "misc.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Game::Game(const Board& board, const Point& sp, const Direction& sd,
           const std::vector<unsigned>& funsizes,
           const std::set<Color>& paint)
  : funsizes_(funsizes), start_d_(sd),
    start_p_(sp), board_(board)
{
  board_colors_init(paint);

  allowed_insert(action::LEFT);
  allowed_insert(action::RIGHT);
  allowed_insert(action::FORWARD);
  allowed_.insert(Instruction(color::NONE, action::NONE));

  for (unsigned i = 0; i < funsizes.size(); ++i)
    allowed_insert(action::CALL, i);
  foreach (const Color& c, paint)
    allowed_insert(action::PAINT, c);
}

Game::Game(const Board& board, const Point& sp, const Direction& sd,
           const std::vector<unsigned>& funsizes,
           const std::set<Instruction>& allowed)
  : allowed_(allowed), funsizes_(funsizes), start_d_(sd),
    start_p_(sp), board_(board)
{
  board_colors_init();
}


bool
Game::valid(const Program& prog) const
{
  if (prog.size() > funsizes_.size())
    return false;

  for (unsigned i = 0; i < prog.size(); ++i)
  {
    const Function& fun = prog[i];

    if (fun.size() > funsizes_[i])
      return false;
    foreach (const Instruction& i, fun)
    {
      bool found = false;

      foreach (const Instruction& a, allowed_)
        if (inst::arg(a)    == inst::arg(i) and
            inst::action(a) == inst::action(i))
          found = true;
      if (not found)
        return false;
    }
  }

  return true;
}

bool
Game::run(const Program& prog)
{
  unsigned stars;
  Processor cpu(prog);
  Ship sh(start_p_, start_d_);

  if (not valid(prog))
    return false;

  board_.reset();
  assert(cell(sh).color() != color::NONE);
  board_.chomp(sh.position());
  stars = board_.stars();
  assert(stars);

  cpu.call(0, board_.cells(), sh);
  while (cpu.count() < Options::max() and cpu.step())
  {
    if (process(cpu, sh))
    {
      if (not board_.valid(sh.position()) or cell(sh).color() == color::NONE)
        return false;
      if (board_.chomp(sh.position()))
      {
        stars -= 1;
        if (stars == 0)
          return true; // YAY \o/
      }
    }

    if (not cpu.running())
      break;
  }

  return false;
}


void
Game::allowed_insert(const Action& a, int arg)
{
  allowed_.insert(Instruction(color::NONE, a, arg));
  if (colors_.size() > 1)
  {
    foreach (const Color& c, colors_)
      if (a != action::PAINT or color::color(arg) != c)
        allowed_.insert(Instruction(c, a, arg));
  }
}

void
Game::board_colors_init(const std::set<Color>& colors)
{
  colors_ = board_.colors();

  foreach (const Color& c, colors)
    colors_.insert(c);
}

void
Game::board_colors_init()
{
  colors_ = board_.colors();

  foreach (const Instruction& i, allowed_)
    if (inst::action(i) == action::PAINT)
      switch (inst::color(i))
      {
        case color::RED:
        case color::BLUE:
        case color::GREEN:
          colors_.insert(inst::color(i));
          break;

        case color::SIZE:
        case color::NONE:
          assert(false);
          break;
      }
}


bool
Game::process(Processor& cpu, Ship& sh)
{
  const Instruction& i = cpu.current();

  if (inst::color(i) == color::NONE or inst::color(i) == cell(sh).color())
  {
    if (Options::verbosity() >= 3)
      std::cout << std::setw(4) << std::right << cpu.count() << ": "
                << std::left << sh << "\t"
                << std::left << i << std::endl;

    switch (inst::action(i))
    {
      case action::LEFT:
        sh.turn_left();
        return false;

      case action::RIGHT:
        sh.turn_right();
        return false;

      case action::FORWARD:
        sh.move_forward();
        return true;

      case action::PAINT:
        board_.paint(sh.position(), color::color(inst::arg(i)));
        return false;

      case action::CALL:
        if (not cpu.call(inst::arg(i), board_.cells(), sh) and Options::verbosity() >= 3)
          std::cout << std::setw(4) << std::right << cpu.count() << ": "
                    << "cycle detected, aborting" << std::endl;
        return false;

      default:
        assert(!"Game::proces: unknown action");
    }
  }

  return false;
}
