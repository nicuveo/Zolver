//
// solver.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef SOLVER_HXX_
# define SOLVER_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline unsigned
Solver::tests() const
{
  return tests_;
}

inline double
Solver::time() const
{
  return time_;
}



#endif /* !SOLVER_HXX_ */
