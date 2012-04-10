//
// game.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GAME_HH_
# define GAME_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "processor.hh"
# include "program.hh"
# include "board.hh"
# include "ship.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Game
{
  public:
    Game(const Board& board, const Point& sp, const Direction& sd,
         const std::vector<unsigned>& funsizes,
         const std::set<Color>& paint = std::set<Color>());
    Game(const Board& board, const Point& sp, const Direction& sd,
         const std::vector<unsigned>& funsizes,
         const std::set<Instruction>& allowed);

    const std::set<Instruction>& allowed_instructions() const;
    const std::vector<unsigned>& program_size() const;
    const std::set<Color>& board_colors() const;

    bool valid(const Program& prog) const;
    bool run(const Program& prog);

  private:
    void allowed_insert(const Action& a, int arg = 0);
    void board_colors_init(const std::set<Color>& colors);
    void board_colors_init();

    const Cell& cell(const Ship& sh) const;

    bool process(Processor& cpu, Ship& sh);

    std::set<Color> colors_;
    std::set<Instruction> allowed_;
    std::vector<unsigned> funsizes_;
    Direction start_d_;
    Point start_p_;
    Board board_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game.hxx"



#endif /* !GAME_HH_ */
