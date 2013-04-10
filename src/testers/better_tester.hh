//
// better_tester.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef BETTER_TESTER_HH_
# define BETTER_TESTER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <map>
# include <set>
# include "testers/basic_tester.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class BetterTester : public BasicTester
{
  public:
    virtual bool test(const Game&, const Program&, int);

  protected:
    virtual bool do_call(Game& g, Processor& proc, int arg);
    virtual bool do_move(Game& g, Processor& proc);

  private:
    struct GameComparator : public std::less<Game>
    {
      public:
        bool operator()(const Game& g1, const Game& g2) const;
    };

    typedef std::set<Game, GameComparator> GameSet;
    typedef std::map<int, GameSet> StateMap;

    StateMap states_;
    int stars_;
};



#endif /* !BETTER_TESTER_HH_ */
