//
// action.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef ACTION_HXX_
# define ACTION_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/action.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace action
{

  inline Type action(int a)
  {
    assert(a >= 0 and a < SIZE);
    return static_cast<Type>(a);
  }


  inline bool require_arg(Type a)
  {
    return a == PAINT or a == CALL;
  }

}



#endif /* !ACTION_HXX_ */
