//
// program.hxx for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef PROGRAM_HXX_
# define PROGRAM_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/program.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline bool
Program::valid(const Point& p) const
{
  return
    p.first  >= 0 and
    p.second >= 0 and
    static_cast<size_t>(p.first)  < size() and
    static_cast<size_t>(p.second) < function(p.first).size();
}


inline Point
Program::first() const
{
  return (empty() or function(0).empty()) ? last() : Point(0, 0);
}

inline Point
Program::last() const
{
  return Point(-1, -1);
}


inline const Function&
Program::function(int f) const
{
  return (*this)[f];
}

inline const Instruction&
Program::instruction(const Point& p) const
{
  return function(p.first)[p.second];
}

inline const Instruction&
Program::instruction(std::size_t index) const
{
  return instruction(position(index));
}

inline Function&
Program::function(int f)
{
  return (*this)[f];
}

inline Instruction&
Program::instruction(const Point& p)
{
  return function(p.first)[p.second];
}

inline Instruction&
Program::instruction(std::size_t index)
{
  return instruction(position(index));
}



#endif /* !PROGRAM_HXX_ */
