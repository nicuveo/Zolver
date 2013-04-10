//
// instruction.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef INSTRUCTION_HXX_
# define INSTRUCTION_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/instruction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline bool
operator==(const Instruction& i1, const Instruction& i2)
{
  return
    i1.action() == i2.action() and
    i1.color()  == i2.color()  and
    i1.arg()    == i2.arg();
}


inline Action
Instruction::action() const
{
  return action_;
}

inline Color
Instruction::color() const
{
  return color_;
}

inline int
Instruction::arg() const
{
  return arg_;
}



#endif /* !INSTRUCTION_HXX_ */
