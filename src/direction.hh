//
// direction.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef DIRECTION_HH_
# define DIRECTION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <ostream>
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


std::ostream& operator<<(std::ostream& ostr, Direction d);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "direction.hxx"



#endif /* !DIRECTION_HH_ */
