//
// ship.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cassert>
#include "ship.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Ship::Ship(const Point& p, Direction d)
  : direction_(d), position_(p)
{
}


void
Ship::move_forward()
{
  switch (direction_)
  {
    case direction::UP:
      position_.second -= 1;
      break;
    case direction::DOWN:
      position_.second += 1;
      break;
    case direction::LEFT:
      position_.first -= 1;
      break;
    case direction::RIGHT:
      position_.first += 1;
      break;
    default:
      assert(!"Ship::process: invalid ship direction");
      break;
  }
}


std::ostream&
operator<<(std::ostream& ostr, const Ship& s)
{
  ostr << "(" << s.position() << ", " << s.direction() << ")";
  return ostr;
}
