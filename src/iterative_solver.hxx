//
// iterative_solver.hxx for altribe
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef ITERATIVE_SOLVER_HXX_
# define ITERATIVE_SOLVER_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "iterative_solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline void
IterativeSolver::reference(const Program& ref)
{
  reference_ = ref;
}



#endif /* !ITERATIVE_SOLVER_HXX_ */
