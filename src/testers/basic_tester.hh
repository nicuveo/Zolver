//
// basic_tester.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef BASIC_TESTER_HH_
# define BASIC_TESTER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/game.hh"
# include "game/program.hh"
# include "game/processor.hh"
# include "testers/tester.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class BasicTester : public Tester
{
  public:
    virtual bool test(const Game&, const Program&, int);

  protected:
    virtual bool process (Game& g, Processor& proc);
    virtual bool do_lturn(Game& g, Processor& proc);
    virtual bool do_rturn(Game& g, Processor& proc);
    virtual bool do_paint(Game& g, Processor& proc, int arg);
    virtual bool do_call (Game& g, Processor& proc, int arg);
    virtual bool do_move (Game& g, Processor& proc);
};



#endif /* !BASIC_TESTER_HH_ */
