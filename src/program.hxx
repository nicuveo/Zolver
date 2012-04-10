//
// program.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef PROGRAM_HXX_
# define PROGRAM_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "program.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace inst
{

  inline int
  arg(const Instruction& inst)
  {
    return inst.get<2>();
  }

  inline const Color&
  color(const Instruction& inst)
  {
    return inst.get<0>();
  }

  inline const Action&
  action(const Instruction& inst)
  {
    return inst.get<1>();
  }

}


inline Function
function(unsigned size)
{
  return Function(size, Instruction(color::NONE, action::NONE));
}


#endif /* !PROGRAM_HXX_ */
