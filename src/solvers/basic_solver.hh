//
// basic_solver.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef BASIC_SOLVER_HH_
# define BASIC_SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solvers/solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class BasicSolver : public Solver
{
  public:
    BasicSolver(const Game& g, Tester& t, int max);

  private:
    virtual Program do_solve();

    bool iterate(unsigned index);

    Program solution_;
    std::vector<Instruction*> inst_;
};



#endif /* !BASIC_SOLVER_HH_ */
