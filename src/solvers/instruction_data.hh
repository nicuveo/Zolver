//
// instruction_data.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//

#ifndef INSTRUCTION_DATA_HH_
# define INSTRUCTION_DATA_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "game/program.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class InstructionData
{
  public:
    InstructionData(std::size_t fun, const Function& allowed);

    std::size_t index() const;
    const Function& allowed() const;

    InstructionData next(const Instruction& inst) const;

  private:
    static InstructionData filter_post_paint(const InstructionData&, const Instruction&);
    static InstructionData filter_post_call (const InstructionData&, const Instruction&);
    static InstructionData filter_direction (const InstructionData&, const Instruction&);

    std::size_t index_;
    std::size_t function_;
    Function allowed_;
    Function all_allowed_;

    bool post_call_;
    ColorSet post_paint_;
    boost::array<int, color::SIZE> direction_;
};



#endif /* !INSTRUCTION_DATA_HH_ */
