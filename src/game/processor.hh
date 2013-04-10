//
// processor.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef PROCESSOR_HH_
# define PROCESSOR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include "game/program.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Processor
{
  public:
    Processor(const Program& p);

    int count() const;
    bool running() const;

    const Point& current_pos() const;
    const Function& current_function() const;
    const Instruction& current_instruction() const;

    bool step();
    void call(int fun);

  private:
    Point& current_pos();

    void pop();

    int count_;
    std::vector<Point> pos_;
    const Program& prog_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/processor.hxx"



#endif /* !PROCESSOR_HH_ */
