//
// program.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef PROGRAM_HH_
# define PROGRAM_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include <boost/tuple/tuple.hpp>
# include "boost/tuple/tuple_comparison.hpp"
# include "action.hh"
# include "color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

typedef boost::tuple<Color, Action, int> Instruction;
typedef std::vector<Instruction>         Function;
typedef std::vector<Function>            Program;


namespace inst
{

  int           arg   (const Instruction& inst);
  const Color&  color (const Instruction& inst);
  const Action& action(const Instruction& inst);

}


Function function(unsigned size);


std::ostream& operator<<(std::ostream& ostr, const Instruction& d);
std::ostream& operator<<(std::ostream& ostr, const Function& d);
std::ostream& operator<<(std::ostream& ostr, const Program& d);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "program.hxx"



#endif /* !PROGRAM_HH_ */
