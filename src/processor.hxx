//
// processor.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef PROCESSOR_HXX_
# define PROCESSOR_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "processor.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline unsigned
Processor::count() const
{
  return count_;
}

inline bool
Processor::running() const
{
  return not pos_.empty();
}


inline const Instruction&
Processor::current() const
{
  assert(running());
  assert(pos().first  >= 0 and static_cast<unsigned>(pos().first)  < prog_.size() and
         pos().second >= 0 and static_cast<unsigned>(pos().second) < prog_[pos().first].size());

  return prog_[pos().first][pos().second];
}


inline const Processor::Position&
Processor::pos() const
{
  assert(running());
  return pos_.back().first;
}

inline Processor::Position&
Processor::pos()
{
  assert(running());
  return pos_.back().first;
}



#endif /* !PROCESSOR_HXX_ */
