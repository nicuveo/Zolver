//
// program.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef PROGRAM_HH_
# define PROGRAM_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include "game/point.hh"
# include "game/instruction.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

typedef std::vector<Instruction> Function;
typedef std::vector<Function>    ProgramBase;
typedef std::vector<std::size_t> ProgramSchema;


class Program : public ProgramBase
{
  public:
    Program();
    Program(const ProgramSchema&);

    bool valid(const Point&) const;
    bool matches(const ProgramSchema&) const;
    std::size_t total_size() const;

    Point first() const;
    Point last() const;
    Point position(std::size_t index) const;
    Point next(const Point& p) const;

    const Function& function(int f) const;
    const Instruction& instruction(const Point& p) const;
    const Instruction& instruction(std::size_t index) const;
    Function& function(int f);
    Instruction& instruction(const Point& p);
    Instruction& instruction(std::size_t index);
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/program.hxx"



#endif /* !PROGRAM_HH_ */
