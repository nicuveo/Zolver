//
// better_solver.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef BETTER_SOLVER_HH_
# define BETTER_SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solvers/solver.hh"
# include "solvers/instruction_data.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class BetterSolver : public Solver
{
  public:
    BetterSolver(const Game& g, Tester& t, int max);

  private:
    virtual Program do_solve();

    Function& nth_fun(std::size_t index);

    bool try_up_to(std::size_t max_fn);
    bool try_function(std::size_t fn, std::size_t max_fn);
    bool try_instruction(const InstructionData& data, std::size_t fn, std::size_t max_fn);

    Program solution_;
    std::vector<std::size_t> funcs_;
};



#endif /* !BETTER_SOLVER_HH_ */
