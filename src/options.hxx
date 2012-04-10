//
// options.hxx for zolver
// Made by nicuveo <crucuny@gmail.com>
//


#ifndef OPTIONS_HXX_
# define OPTIONS_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "options.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

inline const std::vector<std::string>&
Options::files()
{
  return instance_.files_;
}

inline unsigned
Options::verbosity()
{
  return instance_.verbosity_;
}

inline unsigned
Options::max()
{
  return instance_.max_;
}



#endif /* !OPTIONS_HXX_ */
