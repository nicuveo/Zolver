//
// main.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <string>
#include <iomanip>
#include <iostream>
#include "game/game_io.hh"
#include "testers/better_tester.hh"
#include "solvers/basic_solver.hh"
#include "solvers/better_solver.hh"
#include "misc/foreach.hh"
#include "options.hh"
#include "parser.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  template <typename S, typename T>
  Program solve(const std::string& name, const std::string& sname)
  {
    std::cout << "  * " << sname << ": ";

    try
    {
      const Game& game = read(name);
      T tester;
      S solver(game, tester, Options::max());
      Program result = solver.solve();

      std::cout << std::right << std::setw(16) << solver.tests() << " tests"
                << std::right << std::setw(16) << solver.time()  << " seconds";

      if (result.empty())
        std::cout << " => no solution found!" << std::endl;
      else
        std::cout << std::endl;

      return result;
    }
    catch (const std::exception& exc)
    {
      std::cout << "error: " << exc.what() << std::endl;
    }

    return Program();
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

int main(int argc, char** argv)
{
  bool first = true;

  Options::init(argc, argv);

  foreach (const std::string& f, Options::files())
  {
    std::vector<Program> res;

    if (not first)
      std::cout << std::endl << std::endl;

    std::cout << "##### solving " << f << std::endl;
    res.push_back(solve< BasicSolver,  BasicTester>(f, " basic solver,  basic tester"));
    res.push_back(solve< BasicSolver, BetterTester>(f, " basic solver, better tester"));
    res.push_back(solve<BetterSolver,  BasicTester>(f, "better solver,  basic tester"));
    res.push_back(solve<BetterSolver, BetterTester>(f, "better solver, better tester"));

    int i = 0;
    foreach (const Program& p, res)
    {
      i += 1;
      if (not p.empty())
        std::cout << std::endl << "  => solution #" << i << std::endl << p;
    }

    first = false;
  }

  return 0;
}
