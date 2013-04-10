//
// direction.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef DIRECTION_HH_
# define DIRECTION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <cassert>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace direction
{

  enum Type
  {
    UP    = 0,
    LEFT  = 3,
    DOWN  = 2,
    RIGHT = 1
  };


  Type turn_left(Type);
  Type turn_right(Type);

  Type direction(int d);
}

typedef direction::Type Direction;



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/direction.hxx"



#endif /* !DIRECTION_HH_ */
