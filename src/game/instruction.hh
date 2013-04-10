//
// instruction.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef INSTRUCTION_HH_
# define INSTRUCTION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/action.hh"
# include "game/color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

struct Instruction
{
  public:
    Instruction();
    Instruction(Action a, Color c, int arg = 0);

    friend bool operator==(const Instruction& c1, const Instruction& c2);

    Action action() const;
    Color color() const;
    int arg() const;

  private:
    Action action_;
    Color color_;
    int arg_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/instruction.hxx"



#endif /* !INSTRUCTION_HH_ */
