//
// ship.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SHIP_HH_
# define SHIP_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "direction.hh"
# include "point.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Ship
{
  public:
    Ship(const Point& p, Direction d);

    const Direction& direction() const;
    const Point& position() const;

    void turn_left();
    void turn_right();
    void move_forward();

  private:
    Direction direction_;
    Point position_;
};


bool operator==(const Ship& c1, const Ship& c2);

std::ostream& operator<<(std::ostream& ostr, const Ship& s);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "ship.hxx"



#endif /* !SHIP_HH_ */
