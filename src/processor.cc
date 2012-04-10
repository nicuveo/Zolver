//
// processor.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "processor.hh"
#include "misc.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Processor::Processor(const Program& p)
  : prog_(p), count_(0)
{
}


bool
Processor::step()
{
  assert(running());
  assert(pos().second >= -1);
  assert(pos().first >= 0 and static_cast<unsigned>(pos().first) < prog_.size());

  pos().second += 1;
  while (static_cast<unsigned>(pos().second) < prog_[pos().first].size() and
         inst::action(current()) == action::NONE)
    pos().second += 1;

  if (static_cast<unsigned>(pos().second) < prog_[pos().first].size())
  {
    count_ += 1;
    return true;
  }

  pos_.pop_back();
  if (running())
    return step();
  else
    return false;
}


bool
Processor::call(int fun, const std::vector<Cell>& cells, const Ship& ship)
{
  assert(fun >= 0 and static_cast<unsigned>(fun) < prog_.size());

  foreach (const StackElement& se, pos_)
    if (fun == se.first.first and se.second.first == cells and se.second.second == ship)
    {
      pos_.clear();
      return false;
    }

  pos_.push_back(StackElement(Position(fun, -1), MemState(cells, ship)));
  return true;
}
