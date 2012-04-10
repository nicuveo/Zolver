//
// iterative_solver.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <iostream>
#include <algorithm>
#include <boost/bind.hpp>
#include "program.hh"
#include "iterative_solver.hh"
#include "options.hh"
#include "misc.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

InstructionData::InstructionData()
  : prefilled(false)
{
}


IterativeSolver::IterativeSolver(Game& g)
  : Solver(g), board_colors_(g.board_colors())
{
  none_authorized_ =
    std::find(g.allowed_instructions().begin(),
              g.allowed_instructions().end(),
              Instruction(color::NONE, action::NONE)) !=
    g.allowed_instructions().end();

  for (unsigned i = 0; i < game_.program_size().size(); ++i)
    if (i == 0 or game_.program_size()[i] > 1)
      sorted_funs_.push_back(i);
  std::sort(sorted_funs_.begin() + 1, sorted_funs_.end(),
            boost::bind(&IterativeSolver::fun_compare, this, _1, _2));
}


Program
IterativeSolver::do_solve()
{
  init();

  for (unsigned i = 0; i < sorted_funs_.size(); ++i)
  {
    current_.insert(sorted_funs_[i]);

    if (not none_authorized_ and i < sorted_funs_.size() - 1)
      continue;

    foreach (unsigned fun, current_)
      if (not update(fun))
        return Program();

    do
      if (test())
        return solution_;
    while (increment());
  }

  return Program();
}


void
IterativeSolver::copy(const InstructionData& from, InstructionData& to)
{
  to.authorized = from.authorized;
  to.direction = from.direction;
}

bool
IterativeSolver::fun_compare(unsigned f1, unsigned f2) const
{
  return game_.program_size()[f1] < game_.program_size()[f2];
}


void
IterativeSolver::init()
{
  const std::vector<unsigned>& sizes = game_.program_size();

  assert(sorted_funs_.size() <= game_.program_size().size());

  current_.clear();
  solution_.clear();
  solution_data_.clear();
  foreach (unsigned s, sizes)
  {
    solution_.push_back(function(s));
    solution_data_.push_back(FunctionData(s));
  }

  for (unsigned fun = 0; fun < reference_.size(); ++fun)
    for (unsigned inst = 0; inst < reference_[fun].size(); ++inst)
      if (inst::action(reference_[fun][inst]) != action::NONE)
      {
        InstructionData& id = solution_data_[fun][inst];
        Instruction& i = solution_[fun][inst];
        id.prefilled = true;
        i = reference_[fun][inst];
      }
}

bool
IterativeSolver::test()
{
  if (Options::verbosity() > 2)
    std::cout << std::endl;
  if (Options::verbosity() >= 2)
    std::cout << std::endl << solution_;

  return Solver::test(solution_);
}


bool
IterativeSolver::increment()
{
  std::set<unsigned>::iterator it;

  for (it = current_.begin(); it != current_.end(); ++it)
  {
    if (increment(*it))
      return true;
    update(*it);
  }

  return false;
}

bool
IterativeSolver::increment(unsigned fun)
{
  for (unsigned inst = solution_[fun].size(); inst > 0; )
    if (increment(fun, --inst))
      return true;

  return false;
}

bool
IterativeSolver::increment(unsigned fun, unsigned inst)
{
  std::set<Instruction>::const_iterator it;
  InstructionData& id = solution_data_[fun][inst];
  Instruction& i = solution_[fun][inst];

  if (id.prefilled or id.authorized.empty())
    return false;

  it = id.authorized.find(i);
  assert(it != id.authorized.end());

  if (++it == id.authorized.end())
    return false;

  i = *it;
  return update(fun, inst);
}


bool
IterativeSolver::update(unsigned fun)
{
  inst_init(solution_data_[fun][0], fun);
  if (not solution_data_[fun][0].prefilled)
    solution_[fun][0] = *solution_data_[fun][0].authorized.begin();
  else
    if (solution_data_[fun][0].authorized.find(solution_[fun][0]) ==
        solution_data_[fun][0].authorized.end())
      return false;
  for (unsigned i = 1; i < solution_data_[fun].size(); ++i)
    solution_data_[fun][i].authorized.clear();

  return update(fun, 0) ? true : increment(fun);
}

bool
IterativeSolver::update(unsigned fun, unsigned inst)
{
  for (; inst < solution_[fun].size() - 1; ++inst)
  {
    const InstructionData& id_ref = solution_data_[fun][inst];
    InstructionData& id_cur = solution_data_[fun][inst + 1];
    const Instruction& i_ref = solution_[fun][inst];
    Instruction& i_cur = solution_[fun][inst + 1];

    switch (inst::action(i_ref))
    {
      // FORWARD or CALL
      case action::FORWARD:
      case action::CALL:
        inst_full(id_cur, i_ref, fun);
        break;

      // LEFT or RIGHT
      case action::LEFT:
      case action::RIGHT:
        copy(id_ref, id_cur);
        inst_turn(id_cur, i_ref);
        break;

      // PAINT
      case action::PAINT:
        copy(id_ref, id_cur);
        inst_paint(id_cur, i_ref);
        break;

      // NONE
      case action::NONE:
        assert(inst::color(i_ref) == color::NONE);
        id_cur.authorized.clear();
        break;

      case action::SIZE:
        assert(!"unknown action");
    }

    if (none_authorized_ and inst > 0)
      id_cur.authorized.insert(Instruction(color::NONE, action::NONE));

    if (id_cur.prefilled)
    {
      if (id_cur.authorized.find(i_cur) == id_cur.authorized.end())
        return false;
    }
    else
      i_cur = *id_cur.authorized.begin();
  }

  return true;
}


void
IterativeSolver::inst_paint(InstructionData& id, const Instruction& i)
{
  Color ref = color::color(inst::arg(i));

  assert(inst::action(i) == action::PAINT);
  assert(color::valid(ref) and ref != color::NONE);

  if (inst::color(i) == color::NONE)
  {
    foreach (const Instruction& c, game_.allowed_instructions())
      if (inst::color(c) != color::NONE)
        id.authorized.erase(c);
  }
  else
  {
    foreach (const Instruction& c, game_.allowed_instructions())
      if (inst::color(c) == ref)
        id.authorized.erase(c);
  }
}

void
IterativeSolver::inst_turn(InstructionData& id, const Instruction& i)
{
  bool left = false;
  bool right = false;

  assert(inst::action(i) == action::LEFT or inst::action(i) == action::RIGHT);

  if (inst::color(i) != color::NONE)
    id.direction[inst::color(i)] += (inst::action(i) == action::LEFT ? -1 : +1);
  else
    foreach (const Color& c, board_colors_)
      id.direction[c] += (inst::action(i) == action::LEFT ? -1 : +1);

  foreach (const Color& c, board_colors_)
  {
    if (id.direction[c] == 0 or id.direction[c] == 1)
      right = true;
    else
      id.authorized.erase(Instruction(c, action::RIGHT));

    if (id.direction[c] == 0 or id.direction[c] == -1)
      left = true;
    else
      id.authorized.erase(Instruction(c, action::LEFT));
  }

  if (not left)
    id.authorized.erase(Instruction(color::NONE, action::LEFT));
  if (not right)
    id.authorized.erase(Instruction(color::NONE, action::RIGHT));
}

void
IterativeSolver::inst_init(InstructionData& id, unsigned fun)
{
  assert(current_.find(fun) != current_.end());

  foreach (const Color& c, board_colors_)
    id.direction[c] = 0;

  id.authorized.clear();
  foreach (const Instruction& c, game_.allowed_instructions())
  {
    unsigned fc = static_cast<unsigned>(inst::arg(c));

    if ((inst::action(c) != action::CALL or
         (fc != fun and current_.find(fc) != current_.end())) and
        inst::action(c) != action::NONE)
      id.authorized.insert(c);
  }
}

void
IterativeSolver::inst_full(InstructionData& id, const Instruction& i, unsigned fun)
{
  foreach (const Color& c, board_colors_)
    id.direction[c] = 0;

  id.authorized.clear();
  if (i != Instruction(color::NONE, action::CALL, fun))
  {
    foreach (const Instruction& c, game_.allowed_instructions())
    {
      unsigned fc = static_cast<unsigned>(inst::arg(c));

      if ((inst::action(c) != action::CALL or current_.find(fc) != current_.end()) and
          inst::action(c) != action::NONE)
        id.authorized.insert(c);
    }
  }
}
