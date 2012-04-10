//
// parser.cc for zolver
// Made by nicuveo <crucuny@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <fstream>
#include <sstream>
#include <stdexcept>
#include "direction.hh"
#include "parser.hh"
#include "board.hh"
#include "color.hh"
#include "cell.hh"
#include "game.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace
{

  void
  filter(std::string& buf)
  {
    size_t comment = buf.find_first_of('#');
    if (comment != std::string::npos)
      buf.erase(comment);
  }

  void
  bufferize(std::stringstream& ss, const std::string& fn)
  {
    std::ifstream fs;
    std::string buf;

    try
    {
      fs.open(fn.c_str());
      while (std::getline(fs, buf))
      {
        filter(buf);
        ss << buf;
      }
      fs.close();
    }
    catch (...)
    {
      fs.close();
      throw;
    }
  }

}


namespace parser
{

  std::pair<Board*, Game*>
  read(const std::string& filename)
  {
    std::stringstream ss;
    unsigned board_x;
    unsigned board_y;
    int paint_n;
    int inst_n;
    int ship_x;
    int ship_y;
    int ship_d;

    // global
    bufferize(ss, filename);
    ss >> board_x >> board_y >> ship_x >> ship_y >> ship_d;
    assert(board_x > 0);
    assert(board_y > 0);
    assert(ship_x >= 0 and static_cast<unsigned>(ship_x) < board_x);
    assert(ship_y >= 0 and static_cast<unsigned>(ship_y) < board_y);

    // instructions
    ss >> inst_n;
    assert(inst_n > 0);
    std::vector<unsigned> inst_v;
    while (inst_n--)
    {
      unsigned i;
      ss >> i;
      assert(i > 0);
      inst_v.push_back(i);
    }

    // paint
    ss >> paint_n;
    assert(paint_n >= 0);
    std::set<Color> paint_s;
    while (paint_n--)
    {
      unsigned i;
      ss >> i;
      paint_s.insert(color::color(i));
    }

    // board
    std::vector<Cell> board_v(board_x * board_y, color::NONE);
    for (unsigned bs = 0; bs < board_x * board_y; ++bs)
    {
      char c;
      ss >> c;
      switch (c)
      {
        case 'r': board_v[bs] = Cell(color::RED,   false); break;
        case 'R': board_v[bs] = Cell(color::RED,   true);  break;
        case 'g': board_v[bs] = Cell(color::GREEN, false); break;
        case 'G': board_v[bs] = Cell(color::GREEN, true);  break;
        case 'b': board_v[bs] = Cell(color::BLUE,  false); break;
        case 'B': board_v[bs] = Cell(color::BLUE,  true);  break;
        case '_': board_v[bs] = Cell(color::NONE,  false); break;

        default:
          assert(false);
          throw std::runtime_error("invalid cell data");
          break;
      }
    }

    // result
    std::pair<Board*, Game*> res;
    res.first = new Board(board_x, board_y, board_v);
    res.second = new Game(*res.first, Point(ship_x, ship_y),
                          direction::direction(ship_d),
                          inst_v, paint_s);

    return res;
  }

}
