//
// instruction_data.cc for zolver
// Made by nicuveo <antoine.jp.leblanc@gmail.com>
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <boost/bind.hpp>
#include "solvers/instruction_data.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  inline Function null()
  {
    return Function(1);
  }

  inline bool unconditionnal_call(const Instruction& inst)
  {
    return inst.action() == action::CALL and inst.color() == color::NONE;
  }

  inline bool on_color(Color c, const Instruction& inst)
  {
    return inst.color() == c;
  }

  ColorSet possible_colors(const Instruction& inst)
  {
    if (inst.color() == color::NONE)
    {
      ColorSet res = {{ true, false, false, false }};
      return res;
    }
    else
    {
      ColorSet res = {{ true, true, true, true }};
      res[inst.color()] = false;
      return res;
    }
  }

  inline void remove(Function& f, const Instruction& inst)
  {
    f.erase(std::remove(f.begin(), f.end(), inst), f.end());
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

InstructionData::InstructionData(std::size_t fun, const Function& allowed)
  : index_(0), function_(fun), all_allowed_(allowed),
    post_call_(false), post_paint_(color_set())
{
  std::remove_copy_if(allowed.begin(), allowed.end(),
                      std::back_inserter(allowed_),
                      &unconditionnal_call);

  for (int bc = color::NONE; bc < color::SIZE; ++bc)
    direction_[bc] = 0;
}


std::size_t
InstructionData::index() const
{
  return index_;
}

const Function&
InstructionData::allowed() const
{
  return allowed_;
}


InstructionData
InstructionData::next(const Instruction& inst) const
{
  InstructionData res = *this;

  res.index_ += 1;
  res.allowed_ = all_allowed_;

  return
    filter_direction(
      filter_post_paint(
        filter_post_call(
          res,
          inst),
        inst),
      inst);
}


InstructionData
InstructionData::filter_post_paint(const InstructionData& id, const Instruction& i)
{
  // moving from cell resets post paint status

  if (i.action() == action::FORWARD or i.action() == action::CALL)
  {
    InstructionData res = id;

    res.post_paint_ = color_set();

    return res;
  }


  // after a paint call some restrictions may apply

  if (id.post_paint_ != color_set() or i.action() == action::PAINT)
  {
    InstructionData res = id;

    if (i.action() == action::PAINT)
      res.post_paint_ = possible_colors(i);

    for (int bc = color::NONE + 1; bc < color::SIZE; ++bc)
      if (not id.post_paint_[bc])
      {
        Function tmp;

        std::remove_copy_if(res.allowed_.begin(), res.allowed_.end(),
                            std::back_inserter(tmp),
                            boost::bind(&on_color, color::color(bc), _1));
        res.allowed_ = tmp;
      }

    return res;
  }

  return id;
}

InstructionData
InstructionData::filter_post_call(const InstructionData& id, const Instruction& i)
{
  // after an unconditionnal call there can't be any instruction

  if (id.post_call_ or unconditionnal_call(i))
  {
    InstructionData res = id;

    res.post_call_ = true;
    res.allowed_ = null();

    return res;
  }

  return id;
}

InstructionData
InstructionData::filter_direction(const InstructionData& id, const Instruction& i)
{
  InstructionData res = id;


  // moving from cell resets direction status

  if (i.action() == action::FORWARD or i.action() == action::CALL)
  {
    for (int bc = color::NONE; bc < color::SIZE; ++bc)
      res.direction_[bc] = 0;
    return res;
  }


  // if turning, successive calls must not be absurd

  if (i.action() == action::LEFT or i.action() == action::RIGHT)
  {
    if (i.color() != color::NONE)
      res.direction_[i.color()] += (i.action() == action::LEFT ? -1 : +1);
    else
      for (int bc = color::NONE + 1; bc < color::SIZE; ++bc)
        res.direction_[bc] += (i.action() == action::LEFT ? -1 : +1);
  }


  bool left = false;
  bool right = false;

  for (int bc = color::NONE + 1; bc < color::SIZE; ++bc)
  {
    if (res.direction_[bc] == 0 or res.direction_[bc] == 1)
      right = true;
    else
      remove(res.allowed_, Instruction(action::RIGHT, color::color(bc)));

    if (res.direction_[bc] == 0 or res.direction_[bc] == -1)
      left = true;
    else
      remove(res.allowed_, Instruction(action::LEFT, color::color(bc)));
  }

  if (not left)
    remove(res.allowed_, Instruction(action::LEFT, color::NONE));
  if (not right)
    remove(res.allowed_, Instruction(action::RIGHT, color::NONE));

  return res;
}
