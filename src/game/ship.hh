//
// ship.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef SHIP_HH_
# define SHIP_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/direction.hh"
# include "game/point.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Ship
{
  public:
    Ship(const Point& p, Direction d);

    friend bool operator==(const Ship& c1, const Ship& c2);

    Direction direction() const;
    const Point& position() const;

    void turn_left();
    void turn_right();
    void move_forward();

  private:
    Direction direction_;
    Point position_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/ship.hxx"



#endif /* !SHIP_HH_ */
