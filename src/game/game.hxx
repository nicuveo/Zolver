//
// game.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef GAME_HXX_
# define GAME_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/game.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline const ProgramSchema&
Game::program_schema() const
{
  return ps_;
}

inline const ColorSet&
Game::paint_colors() const
{
  return p_colors_;
}

inline const ColorSet&
Game::all_colors() const
{
  return b_colors_;
}

inline const Board&
Game::board() const
{
  return board_;
}

inline const Ship&
Game::ship() const
{
  return ship_;
}

inline const Cell&
Game::cell() const
{
  return board_.cell(ship_.position());
}



#endif /* !GAME_HXX_ */
