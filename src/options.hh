//
// options.hh for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//


#ifndef OPTIONS_HH_
# define OPTIONS_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <string>
# include <vector>
# include <iostream>
# include <boost/program_options.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace po = boost::program_options;

class Options
{
  public:
    static void init(int argc, char** argv);

    static const std::vector<std::string>& files();
    static unsigned verbosity();
    static unsigned max();

  private:
    Options();

    static void usage(std::ostream& ostr, const char* arg, int err);

    po::options_description generic_;
    po::options_description config_;
    po::options_description hidden_;
    po::options_description parsed_;
    po::options_description printed_;
    po::positional_options_description pos_;

    unsigned max_;
    unsigned verbosity_;
    std::vector<std::string> files_;

    static Options instance_;
};



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "options.hxx"



#endif /* !OPTIONS_HH_ */
