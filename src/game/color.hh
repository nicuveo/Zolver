//
// color.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef COLOR_HH_
# define COLOR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/array.hpp>



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
typedef boost::array<bool, color::SIZE> ColorSet;

ColorSet color_set();



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/color.hxx"



#endif /* !COLOR_HH_ */
