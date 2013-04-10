//
// basic_tester.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "testers/basic_tester.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

bool
BasicTester::test(const Game& g, const Program& p, int max_count)
{
  Processor proc(p);
  Game test(g);

  while (proc.step() and proc.count() <= max_count and process(test, proc))
    if (test.solved())
      return true;

  return false;
}

bool
BasicTester::process(Game& g, Processor& proc)
{
  Instruction i = proc.current_instruction();

  if (i.color() == color::NONE or i.color() == g.cell().color())
    switch (i.action())
    {
      case action::LEFT:    return do_lturn(g, proc);
      case action::RIGHT:   return do_rturn(g, proc);
      case action::PAINT:   return do_paint(g, proc, i.arg());
      case action::CALL:    return do_call(g, proc, i.arg());
      case action::FORWARD: return do_move(g, proc);
      default:              return false;
    }
  return true;
}

bool
BasicTester::do_lturn(Game& g, Processor&)
{
  g.turn_ship_left();
  return true;
}

bool
BasicTester::do_rturn(Game& g, Processor&)
{
  g.turn_ship_right();
  return true;
}

bool
BasicTester::do_paint(Game& g, Processor&, int arg)
{
  g.paint_ship_cell(color::color(arg));
  return true;
}

bool
BasicTester::do_call(Game&, Processor& proc, int arg)
{
  proc.call(arg);
  return true;
}

bool
BasicTester::do_move(Game& g, Processor&)
{
  g.move_ship_forward();
  return g.is_valid();
}
