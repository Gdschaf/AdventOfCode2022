#include <functional>

#include "Position.h"

bool Position::operator==(const Position& rhs) const
{
  return first == rhs.first && second == rhs.second;
}