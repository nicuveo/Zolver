//
// color.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

std::ostream& operator<<(std::ostream& ostr, Color c)
{
  switch (c)
  {
    case color::RED:
      ostr << "red";
      break;
    case color::GREEN:
      ostr << "green";
      break;
    case color::BLUE:
      ostr << "blue";
      break;
    case color::NONE:
      break;
    case color::SIZE:
      assert(!"unknown color");
  }

  return ostr;
}
