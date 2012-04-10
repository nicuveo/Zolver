//
// cell.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "cell.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Cell::Cell(Color orig, bool star)
  : star_(star), color_(orig), o_star_(star), o_color_(orig)
{
}


std::ostream&
operator<<(std::ostream& ostr, const Cell& c)
{
  switch (c.color())
  {
    case color::RED:
      ostr << (c.star() ? "R" : "r");
      break;
    case color::GREEN:
      ostr << (c.star() ? "G" : "g");
      break;
    case color::BLUE:
      ostr << (c.star() ? "B" : "b");
      break;
    case color::NONE:
      ostr << " ";
      break;
    case color::SIZE:
      assert(!"unknown color");
      break;
  }
  return ostr;
}
