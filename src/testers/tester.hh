//
// tester.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef TESTER_HH_
# define TESTER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/game.hh"
# include "game/program.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Tester
{
  public:
    virtual bool test(const Game&, const Program&, int max) = 0;
};



#endif /* !TESTER_HH_ */
