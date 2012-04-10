//
// options.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cstdlib>
#include "options.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Options Options::instance_;


Options::Options()
  : generic_(po::options_description("Generic options")),
    config_(po::options_description("Configuration options"))
{
  generic_.add_options()
    ("help,h", "print this help")
    ("verbosity,v", po::value<unsigned>(&verbosity_)->default_value(0), "verbosity level");

  config_.add_options()
    ("max,m", po::value<unsigned>(&max_)->default_value(1000), "instructions limit");

  hidden_.add_options()
    ("file,f",
     po::value<std::vector<std::string> >(&files_),
     "puzzle files");

  parsed_.add(generic_).add(config_).add(hidden_);
  printed_.add(generic_).add(config_);
  pos_.add("file", -1);
}


void
Options::init(int argc, char** argv)
{
  po::variables_map map;

  try
  {
    po::store(po::command_line_parser(argc, argv)
              .options(instance_.parsed_)
              .positional(instance_.pos_)
              .run(), map);
    po::notify(map);
  }
  catch(...)
  {
    usage(std::cerr, *argv, 1);
  }

  if (map.count("help"))
    usage(std::cout, *argv, 0);
  if (not map.count("file"))
    usage(std::cerr, *argv, 2);
}


void
Options::usage(std::ostream& ostr, const char* arg, int err)
{
  ostr << "Usage:" << std::endl
       << "  " << arg << ": [options] puzzle_files" << std::endl
       << instance_.printed_ << std::endl;
  exit(err);
}
