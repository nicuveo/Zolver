//
// main.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <string>
#include <iomanip>
#include <iostream>
#include "parser.hh"
#include "options.hh"
#include "basic_solver.hh"
#include "iterative_solver.hh"
#include "misc.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace
{

  void test_solver(Solver& s, const std::string& name)
  {
    Program p = s.solve();

    std::cout << name
              << "\t" << (p.size() ? " ok" : " ko")
              << "\t" << std::setw(10) << s.tests()
              << "\t" << s.time() << "s" << std::endl;

    if (p.size() and Options::verbosity() > 0)
      std::cout << p;

  }

  void test(const std::string& fn)
  {
    std::pair<Board*, Game*> test = parser::read(fn);

    std::cout << "#### " << fn << std::endl;
    if (Options::verbosity() > 0)
    {
      std::cout << std::endl << "## Board" << std::endl;
      for (unsigned j = 0; j < test.first->height(); ++j)
      {
        for (unsigned i = 0; i < test.first->width(); ++i)
          std::cout << test.first->cell(i, j);
        std::cout << std::endl;
      }

      std::cout << std::endl << "## Instructions set" << std::endl;
      foreach (const Instruction& i, test.second->allowed_instructions())
        std::cout << i << std::endl;

      std::cout << std::endl << "## Results" << std::endl;
    }

    BasicSolver bs(*test.second);
    IterativeSolver is(*test.second);

    test_solver(bs, "naive solver    ");
    test_solver(is, "iterative solver");

    delete test.first;
    delete test.second;
  }

}


int main(int argc, char** argv)
{
  bool first = true;

  Options::init(argc, argv);

  foreach (const std::string& f, Options::files())
  {
    if (not first)
    {
      std::cout << std::endl;
      if (Options::verbosity() > 0)
        std::cout << std::endl;
    }
    test(f);
    first = false;
  }

  return 0;
}
