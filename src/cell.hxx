//
// cell.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef CELL_HXX_
# define CELL_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "cell.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline bool
Cell::star() const
{
  return star_;
}

inline Color
Cell::color() const
{
  return color_;
}


inline void
Cell::color(Color c)
{
  color_ = c;
}


inline void
Cell::reset()
{
  star_ = o_star_;
  color_ = o_color_;
}

inline void
Cell::chomp()
{
  star_ = false;
}


inline bool
operator==(const Cell& c1, const Cell& c2)
{
  return c1.star() == c2.star() and c1.color() == c2.color();
}



#endif /* !CELL_HXX_ */
