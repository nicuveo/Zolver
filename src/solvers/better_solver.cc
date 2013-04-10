//
// better_solver.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/game_io.hh"
#include "solvers/better_solver.hh"
#include "misc/foreach.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  struct FunctionSizeComparer
  {
    public:
      FunctionSizeComparer(const ProgramSchema& ps)
        : ps_(ps)
      {
      }

      inline bool operator()(std::size_t f1, std::size_t f2) const
      {
        return ps_[f1] > ps_[f2];
      }

    private:
      const ProgramSchema& ps_;
  };

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BetterSolver::BetterSolver(const Game& g, Tester& t, int max)
  : Solver(g, t, max)
{
  const ProgramSchema& ps = g.program_schema();

  for (std::size_t i = 0; i < ps.size(); ++i)
    funcs_.push_back(i);
  std::sort(++funcs_.begin(), funcs_.end(), FunctionSizeComparer(ps));

  solution_ = ps;
}


Program
BetterSolver::do_solve()
{
  for (std::size_t s = 1; s <= solution_.size(); ++s)
    if (try_up_to(s))
      return solution_;

  return Program();
}


inline Function&
BetterSolver::nth_fun(std::size_t index)
{
  return solution_[funcs_[index]];
}


bool
BetterSolver::try_up_to(std::size_t max_fn)
{
  return try_function(0, max_fn);
}

bool
BetterSolver::try_function(std::size_t fn, std::size_t max_fn)
{
  if (fn >= max_fn)
    return test(solution_);

  return try_instruction(InstructionData(fn, valid_instructions()), fn, max_fn);
}

bool
BetterSolver::try_instruction(const InstructionData& inst, std::size_t fn, std::size_t max_fn)
{
  const Function& allowed = inst.allowed();
  std::size_t index = inst.index();
  Function& fun = nth_fun(fn);

  if (index >= fun.size())
    return try_function(fn + 1, max_fn);

  foreach (const Instruction& i, allowed)
  {
    fun[index] = i;
    if (try_instruction(inst.next(i), fn, max_fn))
      return true;
  }

  return false;
}
