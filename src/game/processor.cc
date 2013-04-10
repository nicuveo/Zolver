//
// processor.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/processor.hh"
#include "misc/foreach.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Processor::Processor(const Program& p)
  : count_(0), prog_(p)
{
  pos_.reserve(16);
}


bool
Processor::step()
{
  bool rng;

  if (not running())
    call(0);

  while ((rng = running()))
  {
    Point& p = current_pos();

    p.second += 1;
    if (not prog_.valid(p))
      pop();
    else if (current_instruction().action() != action::NONE)
      break;
  }

  assert(not rng or prog_.valid(current_pos()));

  count_ += 1;

  return rng;
}


void
Processor::call(int fun)
{
  pos_.push_back(Point(fun, -1));
}

void
Processor::pop()
{
  pos_.pop_back();
}
