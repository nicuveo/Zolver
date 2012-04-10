//
// color.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef COLOR_HXX_
# define COLOR_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace color
{

  inline bool valid(Type t)
  {
    return t >= NONE and t < SIZE;
  }

  inline Type color(int i)
  {
    assert(valid(static_cast<Type>(i)));
    return static_cast<Type>(i);
  }

}



#endif /* !COLOR_HXX_ */
