//
// basic_solver.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/game_io.hh"
#include "solvers/basic_solver.hh"
#include "misc/foreach.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BasicSolver::BasicSolver(const Game& g, Tester& t, int max)
  : Solver(g, t, max)
{
}


Program
BasicSolver::do_solve()
{
  std::size_t total;

  solution_ = game().program_schema();
  total = solution_.total_size();
  inst_.clear();
  inst_.reserve(total);

  for (std::size_t i = 0; i < total; ++i)
    inst_.push_back(&solution_.instruction(i));

  if (iterate(solution_.total_size()))
    return solution_;

  return Program();
}


bool
BasicSolver::iterate(unsigned index)
{
  if (index == 0)
    return test(solution_);

  index -= 1;

  *inst_[index] = Instruction();
  if (iterate(index))
    return true;

  foreach (const Instruction& in, valid_instructions())
  {
    *inst_[index] = in;
    if (iterate(index))
      return true;
  }

  return false;
}
