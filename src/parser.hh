//
// parser.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef PARSER_HH_
# define PARSER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <algorithm>
# include <string>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Predeclarations

class Board;
class Game;



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace parser
{


  std::pair<Board*, Game*> read(const std::string& filename);


}



#endif /* !PARSER_HH_ */
