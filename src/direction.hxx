//
// direction.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef DIRECTION_HXX_
# define DIRECTION_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "direction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace direction
{

  inline Type turn_left(Type d)
  {
    return static_cast<Type>((d + 3) % 4);
  }

  inline Type turn_right(Type d)
  {
    return static_cast<Type>((d + 1) % 4);
  }


  inline Type direction(int d)
  {
    assert(d >= 0 && d <= 3);
    return static_cast<Type>(d);
  }

}



#endif /* !DIRECTION_HXX_ */
