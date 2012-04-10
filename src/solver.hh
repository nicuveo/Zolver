//
// solver.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SOLVER_HH_
# define SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Solver
{
  public:
    Solver(Game& g);

    unsigned tests() const;
    double time() const;

    Program solve();

  protected:
    virtual Program do_solve() = 0;

    bool test(const Program& solution);

    Game game_;

  private:
    double time_;
    unsigned tests_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solver.hxx"



#endif /* !SOLVER_HH_ */
