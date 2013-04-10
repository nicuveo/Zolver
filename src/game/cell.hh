//
// cell.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef CELL_HH_
# define CELL_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Cell
{
  public:
    Cell(Color orig, bool star = false);

    friend bool operator==(const Cell& c1, const Cell& c2);

    bool star() const;
    Color color() const;

    void chomp();
    void paint(Color c);

  private:
    bool star_;
    Color color_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/cell.hxx"



#endif /* !CELL_HH_ */
