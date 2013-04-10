//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cstdlib>
#include <iostream>

#define BOOST_TEST_MODULE game
#include <boost/test/included/unit_test.hpp>

#include "game/game.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_CASE(test_direction)
{
  BOOST_CHECK_EQUAL(direction::LEFT,  direction::turn_left(direction::UP   ));
  BOOST_CHECK_EQUAL(direction::DOWN,  direction::turn_left(direction::LEFT ));
  BOOST_CHECK_EQUAL(direction::RIGHT, direction::turn_left(direction::DOWN ));
  BOOST_CHECK_EQUAL(direction::UP,    direction::turn_left(direction::RIGHT));

  BOOST_CHECK_EQUAL(direction::RIGHT, direction::turn_right(direction::UP   ));
  BOOST_CHECK_EQUAL(direction::UP,    direction::turn_right(direction::LEFT ));
  BOOST_CHECK_EQUAL(direction::LEFT,  direction::turn_right(direction::DOWN ));
  BOOST_CHECK_EQUAL(direction::DOWN,  direction::turn_right(direction::RIGHT));

  BOOST_CHECK_EQUAL(direction::RIGHT, direction::direction(1));
  BOOST_CHECK_EQUAL(direction::UP,    direction::direction(0));
  BOOST_CHECK_EQUAL(direction::LEFT,  direction::direction(3));
  BOOST_CHECK_EQUAL(direction::DOWN,  direction::direction(2));
}

BOOST_AUTO_TEST_CASE(test_action)
{
  BOOST_CHECK(not action::require_arg(action::LEFT   ));
  BOOST_CHECK(not action::require_arg(action::RIGHT  ));
  BOOST_CHECK(not action::require_arg(action::FORWARD));
  BOOST_CHECK(    action::require_arg(action::CALL   ));
  BOOST_CHECK(    action::require_arg(action::PAINT  ));
}

BOOST_AUTO_TEST_CASE(test_cell)
{
  Cell c0(color::NONE,  false);
  Cell c1(color::RED,   false);
  Cell c2(color::GREEN, false);
  Cell c3(color::BLUE,  false);
  Cell c4(color::RED,   true);
  Cell c5(color::GREEN, true);
  Cell c6(color::BLUE,  true);

  BOOST_CHECK(not c0.star());
  BOOST_CHECK(not c1.star());
  BOOST_CHECK(not c2.star());
  BOOST_CHECK(not c3.star());
  BOOST_CHECK(    c4.star());
  BOOST_CHECK(    c5.star());
  BOOST_CHECK(    c6.star());

  c0.chomp();
  c1.chomp();
  c2.chomp();
  c3.chomp();
  c4.chomp();
  c5.chomp();
  c6.chomp();

  BOOST_CHECK(not c0.star());
  BOOST_CHECK(not c1.star());
  BOOST_CHECK(not c2.star());
  BOOST_CHECK(not c3.star());
  BOOST_CHECK(not c4.star());
  BOOST_CHECK(not c5.star());
  BOOST_CHECK(not c6.star());

  BOOST_CHECK_EQUAL(color::NONE,  c0.color());
  BOOST_CHECK_EQUAL(color::RED,   c1.color());
  BOOST_CHECK_EQUAL(color::GREEN, c2.color());
  BOOST_CHECK_EQUAL(color::BLUE,  c3.color());
  BOOST_CHECK_EQUAL(color::RED,   c4.color());
  BOOST_CHECK_EQUAL(color::GREEN, c5.color());
  BOOST_CHECK_EQUAL(color::BLUE,  c6.color());

  c0.paint(color::BLUE);
  c1.paint(color::BLUE);
  c2.paint(color::BLUE);
  c3.paint(color::BLUE);
  c4.paint(color::BLUE);
  c5.paint(color::BLUE);
  c6.paint(color::BLUE);

  BOOST_CHECK_EQUAL(color::BLUE, c0.color());
  BOOST_CHECK_EQUAL(color::BLUE, c1.color());
  BOOST_CHECK_EQUAL(color::BLUE, c2.color());
  BOOST_CHECK_EQUAL(color::BLUE, c3.color());
  BOOST_CHECK_EQUAL(color::BLUE, c4.color());
  BOOST_CHECK_EQUAL(color::BLUE, c5.color());
  BOOST_CHECK_EQUAL(color::BLUE, c6.color());
}
