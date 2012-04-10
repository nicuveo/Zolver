//
// direction.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "direction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

std::ostream& operator<<(std::ostream& ostr, Direction d)
{
  switch (d)
  {
    case direction::UP:
      ostr << "up";
      break;
    case direction::LEFT:
      ostr << "left";
      break;
    case direction::DOWN:
      ostr << "down";
      break;
    case direction::RIGHT:
      ostr << "right";
      break;
  }

  return ostr;
}
