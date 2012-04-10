//
// board.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "board.hh"
#include "misc.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Board::Board(unsigned size_x, unsigned size_y)
  : w_(size_x),  h_(size_y), c_(w_ * h_, color::NONE)
{
  assert(w_);
  assert(h_);
}

Board::Board(unsigned size_x, unsigned size_y, const std::vector<Cell>& cells)
  : w_(size_x),  h_(size_y), c_(cells)
{
  assert(w_);
  assert(h_);
  assert(c_.size() == w_ * h_);
}


bool
Board::cleared() const
{
  foreach (const Cell& c, c_)
    if (c.star())
      return false;

  return true;
}

unsigned
Board::stars() const
{
  unsigned s = 0;

  foreach (const Cell& c, c_)
    if (c.star())
      s += 1;

  return s;
}

std::set<Color>
Board::colors() const
{
  std::set<Color> res;

  foreach (const Cell& c, c_)
    res.insert(c.color());

  return res;
}


bool
Board::chomp(const Point& p)
{
  assert(valid(p));

  bool res = cell(p).star();
  rcell(p).chomp();

  return res;
}

bool
Board::paint(const Point& p, const Color& c)
{
  assert(valid(p));
  assert(cell(p).color() != color::NONE);

  bool id = cell(p).color() == c;
  if (not id)
    rcell(p).color(c);
  return not id;
}


void
Board::reset()
{
  foreach (Cell& c, c_)
    c.reset();
}
