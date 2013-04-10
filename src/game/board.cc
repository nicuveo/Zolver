//
// board.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/board.hh"
#include "misc/foreach.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Board::Board()
  : w_(0), h_(0)
{
}

Board::Board(int size_x, int size_y, const Cells& cells)
  : w_(size_x),  h_(size_y), c_(cells)
{
  assert(w_ > 0);
  assert(h_ > 0);
  assert(c_.size() == static_cast<unsigned>(w_ * h_));
}


bool
Board::cleared() const
{
  foreach (const Cell& c, c_)
    if (c.star())
      return false;

  return true;
}

int
Board::stars() const
{
  int s = 0;

  foreach (const Cell& c, c_)
    if (c.star())
      s += 1;

  return s;
}

ColorSet
Board::colors() const
{
  ColorSet res;

  foreach (const Cell& c, c_)
    res[c.color()] = true;

  return res;
}


bool
Board::chomp(const Point& p)
{
  assert(valid(p));

  Cell& cell = rcell(p);
  bool res = cell.star();

  cell.chomp();

  return res;
}

bool
Board::paint(const Point& p, const Color& c)
{
  assert(valid(p));
  assert(cell(p).color() != color::NONE);

  Cell& cell = rcell(p);
  bool res = cell.color() != c;

  cell.paint(c);

  return res;
}
