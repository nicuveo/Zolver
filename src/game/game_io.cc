//
// game_io.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/game_io.hh"



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

std::ostream&
operator<<(std::ostream& ostr, const Ship& s)
{
  ostr << "(" << s.position() << ", " << s.direction() << ")";
  return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const Point& p)
{
  ostr << "(" << p.first << ", " << p.second << ")";
  return ostr;
}

std::ostream&
operator<<(std::ostream& ostr, const Program& p)
{
  for (unsigned i = 0; i < p.size(); ++i)
    ostr << "F" << i + 1 << ": " << p[i] << std::endl;

  return ostr;
}

std::ostream&
operator<<(std::ostream& ostr, const Function& f)
{
  if (not f.empty())
  {
    ostr << f[0];
    for (unsigned i = 1; i < f.size(); ++i)
      ostr << ", " << f[i];
  }

  return ostr;
}

std::ostream&
operator<<(std::ostream& ostr, const Instruction& i)
{
  if (i.color() != color::NONE)
    ostr << "on " << i.color() << " ";

  switch (i.action())
  {
    case action::PAINT:
      ostr << i.action() << " " << color::color(i.arg());
      break;
    case action::CALL:
      ostr << i.action() << " F" << i.arg() + 1;
      break;
    default:
      ostr << i.action();
      break;
  }

  return ostr;
}

std::ostream&
operator<<(std::ostream& ostr, const ColorSet& c)
{
  ostr << "{";
  for (int i = color::NONE; i < color::SIZE; ++i)
  {
    if (i == color::NONE)
      ostr << "empty: ";
    else
      ostr << ", " << i << ": ";
    ostr << c[i];
  }
  ostr << "}";
  return ostr;
}
