//
// board.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef BOARD_HXX_
# define BOARD_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/board.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline int
Board::width() const
{
  return w_;
}

inline int
Board::height() const
{
  return h_;
}

inline bool
Board::empty() const
{
  return c_.empty();
}


inline bool
Board::valid(int x, int y) const
{
  return (x >= 0 and x < w_ and
          y >= 0 and y < h_);
}

inline bool
Board::valid(const Point& p) const
{
  return valid(p.first, p.second);
}


inline const Board::Cells&
Board::cells() const
{
  return c_;
}


inline Cell&
Board::rcell(int x, int y)
{
  assert(valid(x, y));
  return c_[y * w_ + x];
}

inline const Cell&
Board::cell(int x, int y) const
{
  assert(valid(x, y));
  return c_[y * w_ + x];
}

inline Cell&
Board::rcell(const Point& s)
{
  return rcell(s.first, s.second);
}

inline const Cell&
Board::cell(const Point& s) const
{
  return cell(s.first, s.second);
}



#endif /* !BOARD_HXX_ */
