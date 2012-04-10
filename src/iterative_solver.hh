//
// iterative_solver.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef ITERATIVE_SOLVER_HH_
# define ITERATIVE_SOLVER_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <map>
# include "solver.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

struct InstructionData
{
  public:
    InstructionData();

    bool prefilled;
    std::map<Color, int> direction;
    std::set<Instruction> authorized;
};


class IterativeSolver : public Solver
{
  public:
    IterativeSolver(Game& g);

    void reference(const Program& ref);

  private:
    virtual Program do_solve();

    static void copy(const InstructionData& from, InstructionData& to);
    bool fun_compare(unsigned f1, unsigned f2) const;

    void init();
    bool test();

    bool increment();
    bool increment(unsigned fun);
    bool increment(unsigned fun, unsigned inst);

    bool update(unsigned fun);
    bool update(unsigned fun, unsigned inst);

    void inst_paint(InstructionData& id, const Instruction& i);
    void inst_turn(InstructionData& id, const Instruction& i);
    void inst_full(InstructionData& id, const Instruction& i, unsigned fun);
    void inst_init(InstructionData& id, unsigned fun);

    typedef std::vector<InstructionData> FunctionData;
    typedef std::vector<FunctionData> ProgramData;

    std::set<unsigned> current_;
    ProgramData solution_data_;
    Program solution_;

    Program reference_;

    bool none_authorized_;
    std::vector<unsigned> sorted_funs_;
    const std::set<Color> board_colors_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "iterative_solver.hxx"



#endif /* !ITERATIVE_SOLVER_HH_ */
