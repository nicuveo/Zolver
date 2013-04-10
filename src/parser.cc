//
// parser.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game/game.hh"
#include "parser.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

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



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Game
read(const std::string& filename)
{
  std::stringstream ss;
  Board::Cells cells;
  ProgramSchema ps;
  ColorSet cs;
  int board_x;
  int board_y;
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
  assert(ship_x >= 0 and ship_x < board_x);
  assert(ship_y >= 0 and ship_y < board_y);

  // instructions
  ss >> inst_n;
  assert(inst_n > 0);
  while (inst_n--)
  {
    std::size_t i;
    ss >> i;
    assert(i > 0);
    ps.push_back(i);
  }

  // paint
  ss >> paint_n;
  assert(paint_n >= 0);

  cs = color_set();
  while (paint_n--)
  {
    int i;
    ss >> i;
    assert(i > 0 and static_cast<std::size_t>(i) < cs.size());
    cs[i] = true;
  }

  // board
  cells = Board::Cells(board_x * board_y, color::NONE);
  for (int bs = 0; bs < board_x * board_y; ++bs)
  {
    char c;
    ss >> c;
    switch (c)
    {
      case 'r': cells[bs] = Cell(color::RED,   false); break;
      case 'R': cells[bs] = Cell(color::RED,   true);  break;
      case 'g': cells[bs] = Cell(color::GREEN, false); break;
      case 'G': cells[bs] = Cell(color::GREEN, true);  break;
      case 'b': cells[bs] = Cell(color::BLUE,  false); break;
      case 'B': cells[bs] = Cell(color::BLUE,  true);  break;
      case '_': cells[bs] = Cell(color::NONE,  false); break;

      default:
        assert(false);
        throw std::runtime_error("invalid cell data");
        break;
    }
  }

  // result
  return Game(Board(board_x, board_y, cells),
              Ship(Point(ship_x, ship_y), direction::direction(ship_d)),
              ps, cs);
}
