//
// board.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef BOARD_HH_
# define BOARD_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <set>
# include <vector>
# include "game/cell.hh"
# include "game/point.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Board
{
  public:
    typedef std::vector<Cell> Cells;

    Board();
    Board(int size_x, int size_y, const Cells& cells);

    friend bool operator==(const Board& c1, const Board& c2);

    int width() const;
    int height() const;
    bool empty() const;

    bool valid(int x, int y) const;
    bool valid(const Point& p) const;

    int stars() const;
    bool cleared() const;
    ColorSet colors() const;

    const Cell& cell(int x, int y) const;
    const Cell& cell(const Point& s) const;

    const Cells& cells() const;

    bool chomp(const Point& p);
    bool paint(const Point& p, const Color& c);

  private:
    Cell& rcell(int x, int y);
    Cell& rcell(const Point& s);

    int w_;
    int h_;
    Cells c_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/board.hxx"



#endif /* !BOARD_HH_ */
