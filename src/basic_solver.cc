//
// basic_solver.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "options.hh"
#include "basic_solver.hh"
#include "misc.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BasicSolver::BasicSolver(Game& g)
  : Solver(g)
{
}


Program
BasicSolver::do_solve()
{
  unsigned psize = 0;

  solution_.clear();
  foreach (unsigned s, game_.program_size())
  {
    solution_.push_back(function(s));
    psize += s;
  }

  std::vector<Instruction> prg(psize);

  if (iterate(prg, prg.size() - 1))
    return solution_;
  return Program();
}


bool
BasicSolver::iterate(std::vector<Instruction>& prg, unsigned index)
{
  foreach (const Instruction& in, game_.allowed_instructions())
  {
    prg[index] = in;
    if (index > 0)
    {
      if (iterate(prg, index - 1))
        return true;
    }
    else
    {
      if (test(prg))
        return true;
    }
  }
  return false;
}

bool
BasicSolver::test(const std::vector<Instruction>& prg)
{
  unsigned index = 0;

  foreach (Function& fun, solution_)
    foreach (Instruction& instr, fun)
      instr = prg[index++];
  assert(index == prg.size());

  if (Options::verbosity() > 2)
    std::cout << std::endl;
  if (Options::verbosity() >= 2)
    std::cout << std::endl << solution_;

  return Solver::test(solution_);
}
