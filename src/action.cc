//
// action.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cassert>
#include "action.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace action
{

  Type action(int a)
  {
    assert(a >= 0 and a < SIZE);
    return static_cast<Type>(a);
  }

}

std::ostream& operator<<(std::ostream& ostr, Action a)
{
  switch (a)
  {
    case action::LEFT:
      ostr << "turn left";
      break;
    case action::RIGHT:
      ostr << "turn right";
      break;
    case action::FORWARD:
      ostr << "move forward";
      break;
    case action::CALL:
      ostr << "call function";
      break;
    case action::PAINT:
      ostr << "paint cell";
      break;
    case action::NONE:
      ostr << "noop";
      break;
    case action::SIZE:
      assert(!"unknown action");
      break;
  }

  return ostr;
}
