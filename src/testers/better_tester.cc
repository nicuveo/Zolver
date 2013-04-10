//
// better_tester.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "testers/better_tester.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

bool
BetterTester::test(const Game& g, const Program& p, int max_count)
{
  Processor proc(p);
  Game test(g);

  stars_ = g.board().stars();
  states_.clear();

  while (proc.step() and proc.count() <= max_count and process(test, proc))
    if (stars_ == 0)
      return true;

  return false;
}

bool
BetterTester::do_call(Game& g, Processor& proc, int arg)
{
  GameSet& s = states_[arg];
  std::pair<GameSet::iterator, bool> p;

  p = s.insert(g);
  proc.call(arg);

  return p.second;
}

bool
BetterTester::do_move(Game& g, Processor&)
{
  if (g.move_ship_forward())
    stars_ -= 1;
  return g.is_valid();
}


bool
BetterTester::GameComparator::operator()(const Game& g1, const Game& g2) const
{
  const Board::Cells& b1 = g1.board().cells();
  const Board::Cells& b2 = g2.board().cells();
  const Ship& s1 = g1.ship();
  const Ship& s2 = g2.ship();

  if (s1.direction() != s2.direction())
    return s1.direction() < s2.direction();
  if (s1.position() != s2.position())
    return s1.position() < s2.position();

  if (b1.size() != b2.size())
    return b1.size() < b2.size();

  for (std::size_t i = 0; i < b1.size(); ++i)
  {
    const Cell& c1 = b1[i];
    const Cell& c2 = b2[i];

    if (c1.color() != c2.color())
      return c1.color() < c2.color();
    if (c1.star() != c2.star())
      return c1.star() < c2.star();
  }

  return false;
}
