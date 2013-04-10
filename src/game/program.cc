//
// program.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "game/program.hh"
#include "misc/foreach.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Program::Program()
{
}

Program::Program(const ProgramSchema& ps)
{
  reserve(ps.size());
  foreach (size_t fsize, ps)
    push_back(Function(fsize));
}


bool
Program::matches(const ProgramSchema& ps) const
{
  std::size_t s = size();

  if (s != ps.size())
    return false;
  for (std::size_t i = 0; i < s; ++i)
    if ((*this)[i].size() != ps[i])
      return false;
  return true;
}

std::size_t
Program::total_size() const
{
  std::size_t res = 0;

  for (std::size_t i = 0; i < size(); ++i)
    res += function(i).size();

  return res;
}


Point
Program::position(std::size_t index) const
{
  for (std::size_t i = 0; i < size(); ++i)
  {
    std::size_t s = function(i).size();
    if (index < s)
      return Point(i, index);
    else
      index -= s;
  }

  return last();
}

Point
Program::next(const Point& p) const
{
  Point res = p;

  if (p.first < 0 or static_cast<std::size_t>(p.first) >= size())
    return last();

  res.second += 1;

  while (static_cast<std::size_t>(res.second) >= function(p.first).size())
  {
    res.first += 1;
    res.second = 0;

    if (static_cast<std::size_t>(res.first) == size())
      return last();
  }

  return res;
}
