//
// cell.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef CELL_HH_
# define CELL_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Cell
{
  public:
    Cell(Color orig, bool star = false);

    bool star() const;
    Color color() const;

    void color(Color c);

    void reset();
    void chomp();

  private:
    bool star_;
    Color color_;
    bool o_star_;
    Color o_color_;
};


bool operator==(const Cell& c1, const Cell& c2);

std::ostream& operator<<(std::ostream& ostr, const Cell& c);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "cell.hxx"



#endif /* !CELL_HH_ */
