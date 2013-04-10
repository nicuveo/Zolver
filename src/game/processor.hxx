//
// processor.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef PROCESSOR_HXX_
# define PROCESSOR_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/processor.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline int
Processor::count() const
{
  return count_;
}

inline bool
Processor::running() const
{
  return not pos_.empty();
}


inline Point&
Processor::current_pos()
{
  return pos_.back();
}

inline const Point&
Processor::current_pos() const
{
  return pos_.back();
}

inline const Function&
Processor::current_function() const
{
  return prog_.function(current_pos().first);
}

inline const Instruction&
Processor::current_instruction() const
{
  return prog_.instruction(current_pos());
}



#endif /* !PROCESSOR_HXX_ */
