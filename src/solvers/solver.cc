//
// solver.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <ctime>
#include "solvers/solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  ColorSet filter(const ColorSet& cs)
  {
    ColorSet res = cs;
    int c = color::NONE;

    res[color::NONE] = true;

    for (int bc = color::NONE + 1; bc < color::SIZE; ++bc)
      if (res[bc])
      {
        if (c > color::NONE)
          return res;
        c = bc;
      }

    res[c] = false;

    return res;
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Solver::Solver(const Game& g, Tester& t, int max)
  : game_(g), tester_(t), time_(0), tests_(0), max_(max)
{
  const ColorSet& p = g.paint_colors();
  ColorSet c = filter(g.all_colors());

  for (int bc = color::NONE; bc < color::SIZE; ++bc)
    if (c[bc])
    {
      valid_instructions_.push_back(Instruction(action::LEFT,    color::color(bc)));
      valid_instructions_.push_back(Instruction(action::RIGHT,   color::color(bc)));
      valid_instructions_.push_back(Instruction(action::FORWARD, color::color(bc)));

      for (int pc = color::NONE; pc < color::SIZE; ++pc)
        if (p[pc])
          valid_instructions_.push_back(Instruction(action::PAINT, color::color(bc), pc));

      for (std::size_t fn = 0; fn < g.program_schema().size(); ++fn)
        valid_instructions_.push_back(Instruction(action::CALL, color::color(bc), fn));
    }
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
  return tester_.test(game_, solution, max_);
}
