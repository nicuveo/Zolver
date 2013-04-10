//
// solver.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef SOLVER_HXX_
# define SOLVER_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solvers/solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline int
Solver::tests() const
{
  return tests_;
}

inline double
Solver::time() const
{
  return time_;
}


inline const Game&
Solver::game() const
{
  return game_;
}

inline const Function&
Solver::valid_instructions() const
{
  return valid_instructions_;
}



#endif /* !SOLVER_HXX_ */
