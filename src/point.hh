//
// point.hh for zolver
// Made by nicuveo <crucuny@gmail.com>
//

#ifndef POINT_HH_
# define POINT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <ostream>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

typedef std::pair<int, int> Point;


std::ostream& operator<<(std::ostream& ostr, Point p);



#endif /* !POINT_HH_ */
