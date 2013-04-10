//
// game.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef GAME_HH_
# define GAME_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/processor.hh"
# include "game/program.hh"
# include "game/board.hh"
# include "game/ship.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Game
{
  public:
    Game(const Board& board,
         const Ship& ship,
         const ProgramSchema& program,
         const ColorSet& paint = ColorSet());

    const ProgramSchema& program_schema() const;
    const ColorSet& paint_colors() const;
    const ColorSet& all_colors() const;
    const Board& board() const;
    const Ship& ship() const;
    const Cell& cell() const;

    bool allowed(const Instruction& inst) const;
    bool allowed(const Function& fun) const;
    bool allowed(const Program& prog) const;
    bool is_valid() const;
    bool solved() const;

    void turn_ship_left();
    void turn_ship_right();
    bool move_ship_forward();
    void paint_ship_cell(Color c);

  private:
    ProgramSchema ps_;
    ColorSet p_colors_;
    ColorSet b_colors_;
    Board board_;
    Ship ship_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/game.hxx"



#endif /* !GAME_HH_ */
