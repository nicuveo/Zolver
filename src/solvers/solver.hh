//
// solver.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef SOLVER_HH_
# define SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/game.hh"
# include "testers/tester.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Solver
{
  public:
    Solver(const Game& g, Tester& t, int max);

    int tests() const;
    double time() const;

    Program solve();

  protected:
    const Game& game() const;
    const Function& valid_instructions() const;

    bool test(const Program& solution);

    virtual Program do_solve() = 0;

  private:
    const Game& game_;
    Tester& tester_;

    Function valid_instructions_;
    double time_;
    int tests_;
    int max_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solvers/solver.hxx"



#endif /* !SOLVER_HH_ */
