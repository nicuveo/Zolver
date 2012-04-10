//
// board.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef BOARD_HH_
# define BOARD_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <set>
# include <vector>
# include <fstream>
# include <cassert>
# include <sstream>
# include "cell.hh"
# include "point.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Board
{
  public:
    Board(unsigned size_x, unsigned size_y);
    Board(unsigned size_x, unsigned size_y, const std::vector<Cell>& cells);

    unsigned width() const;
    unsigned height() const;

    bool valid(int x, int y) const;
    bool valid(const Point& p) const;

    bool cleared() const;
    unsigned stars() const;
    std::set<Color> colors() const;

    const Cell& cell(int x, int y) const;
    const Cell& cell(const Point& s) const;

    const std::vector<Cell>& cells() const;

    bool chomp(const Point& p);
    bool paint(const Point& p, const Color& c);

    void reset();

  private:
    Cell& rcell(int x, int y);
    Cell& rcell(const Point& s);

    unsigned w_;
    unsigned h_;
    std::vector<Cell> c_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "board.hxx"



#endif /* !BOARD_HH_ */
