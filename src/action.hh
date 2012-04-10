//
// action.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef ACTION_HH_
# define ACTION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <set>
# include <ostream>



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

}

typedef action::Type Action;


std::ostream& operator<<(std::ostream& ostr, Action a);



#endif /* !ACTION_HH_ */
