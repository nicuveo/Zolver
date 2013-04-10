//
// game_io.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef GAME_IO_HH_
# define GAME_IO_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <iostream>
# include "game/cell.hh"
# include "game/ship.hh"
# include "game/point.hh"
# include "game/color.hh"
# include "game/action.hh"
# include "game/program.hh"
# include "game/direction.hh"
# include "game/instruction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

std::ostream& operator<<(std::ostream& ostr, Color c);
std::ostream& operator<<(std::ostream& ostr, Action a);
std::ostream& operator<<(std::ostream& ostr, Direction d);
std::ostream& operator<<(std::ostream& ostr, const Cell& c);
std::ostream& operator<<(std::ostream& ostr, const Ship& s);
std::ostream& operator<<(std::ostream& ostr, const Point& p);
std::ostream& operator<<(std::ostream& ostr, const Program& d);
std::ostream& operator<<(std::ostream& ostr, const Function& d);
std::ostream& operator<<(std::ostream& ostr, const Instruction& d);
std::ostream& operator<<(std::ostream& ostr, const ColorSet& cs);



#endif /* !GAME_IO_HH_ */
