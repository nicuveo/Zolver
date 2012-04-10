//
// program.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "program.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

std::ostream&
operator<<(std::ostream& ostr, const Instruction& i)
{
  if (inst::color(i) != color::NONE)
    ostr << "on " << inst::color(i) << " ";

  switch (inst::action(i))
  {
    case action::PAINT:
      ostr << inst::action(i) << " " << color::color(inst::arg(i));
      break;
    case action::CALL:
      ostr << inst::action(i) << " F" << inst::arg(i) + 1;
      break;
    default:
      ostr << inst::action(i);
      break;
  }

  return ostr;
}

std::ostream&
operator<<(std::ostream& ostr, const Function& f)
{
  if (f.size())
  {
    ostr << f[0];
    for (unsigned i = 1; i < f.size(); ++i)
      ostr << ", " << f[i];
  }

  return ostr;
}

std::ostream&
operator<<(std::ostream& ostr, const Program& p)
{
  if (p.size())
  {
    for (unsigned i = 0; i < p.size(); ++i)
      ostr << "F" << i + 1 << ": " << p[i] << std::endl;
  }

  return ostr;
}
