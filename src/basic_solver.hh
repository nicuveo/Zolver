//
// basic_solver.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef BASIC_SOLVER_HH_
# define BASIC_SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class BasicSolver : public Solver
{
  public:
    BasicSolver(Game& g);

  private:
    virtual Program do_solve();

    bool iterate(std::vector<Instruction>& prg, unsigned index);
    bool test(const std::vector<Instruction>& prg);

    Program solution_;
};



#endif /* !BASIC_SOLVER_HH_ */
