//
// solver.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <ctime>
#include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Solver::Solver(Game& g)
  : game_(g), tests_(0)
{
}


Program
Solver::solve()
{
  clock_t b;
  clock_t e;

  tests_ = 0;

  b = clock();
  const Program& res = do_solve();
  e = clock();
  time_ = (e - b) / static_cast<double>(CLOCKS_PER_SEC);

  return res;
}


bool
Solver::test(const Program& solution)
{
  tests_ += 1;
  return game_.run(solution);
}
