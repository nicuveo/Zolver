//
// instruction.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/instruction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Instruction::Instruction()
  : action_(action::NONE),
    color_(color::NONE),
    arg_(0)
{
}

Instruction::Instruction(Action a, Color c, int arg)
  : action_(a), color_(c), arg_(arg)
{
  assert(arg == 0 or action::require_arg(a));
}
