//
// game.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef GAME_HXX_
# define GAME_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline const std::set<Instruction>&
Game::allowed_instructions() const
{
  return allowed_;
}

inline const std::vector<unsigned>&
Game::program_size() const
{
  return funsizes_;

}

inline const std::set<Color>&
Game::board_colors() const
{
  return colors_;
}


inline const Cell&
Game::cell(const Ship& sh) const
{
  assert(board_.valid(sh.position()));
  return board_.cell(sh.position());
}



#endif /* !GAME_HXX_ */
