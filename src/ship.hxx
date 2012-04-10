//
// ship.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SHIP_HXX_
# define SHIP_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "ship.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline const Direction&
Ship::direction() const
{
  return direction_;
}

inline const Point&
Ship::position() const
{
  return position_;
}


inline void
Ship::turn_left()
{
  direction_ = direction::turn_left(direction_);
}

inline void
Ship::turn_right()
{
  direction_ = direction::turn_right(direction_);
}


inline bool
operator==(const Ship& s1, const Ship& s2)
{
  return s1.position() == s2.position() and s1.direction() == s2.direction();
}



#endif /* !SHIP_HXX_ */
