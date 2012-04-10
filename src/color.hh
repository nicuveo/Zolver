//
// color.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef COLOR_HH_
# define COLOR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <cassert>
# include <ostream>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace color
{

  enum Type
  {
    NONE = 0,

    RED,
    GREEN,
    BLUE,

    SIZE
  };


  bool valid(Type t);
  Type color(int i);

}

typedef color::Type Color;


std::ostream& operator<<(std::ostream& ostr, Color c);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "color.hxx"



#endif /* !COLOR_HH_ */
