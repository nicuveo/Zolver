//
// action.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef ACTION_HH_
# define ACTION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <cassert>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace action
{

  enum Type
  {
    NONE = 0,

    LEFT,
    RIGHT,
    FORWARD,

    CALL,

    PAINT,

    SIZE
  };


  Type action(int a);

  bool require_arg(Type a);

}

typedef action::Type Action;



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/action.hxx"



#endif /* !ACTION_HH_ */
