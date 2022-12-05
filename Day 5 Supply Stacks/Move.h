#pragma once

#include <string>

class Move
{
public:
  Move(std::string input);
  int Count() { return moveCount; }
  int From() { return fromIndex; }
  int To() { return toIndex; }
private:
  int fromIndex, toIndex, moveCount;
};