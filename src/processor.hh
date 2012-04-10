//
// processor.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef PROCESSOR_HH_
# define PROCESSOR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <list>
# include <cassert>
# include "program.hh"
# include "cell.hh"
# include "ship.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Processor
{
  public:
    Processor(const Program& p);

    unsigned count() const;
    bool running() const;

    const Instruction& current() const;
    bool step();

    bool call(int fun, const std::vector<Cell>& cells, const Ship& ship);

  private:
    typedef std::pair<int, int> Position;
    typedef std::pair<std::vector<Cell>, Ship> MemState;
    typedef std::pair<Position, MemState> StackElement;

    const Position& pos() const;
    Position& pos();

    const Program& prog_;

    unsigned count_;
    std::list<StackElement> pos_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "processor.hxx"



#endif /* !PROCESSOR_HH_ */
