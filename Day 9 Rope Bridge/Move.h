#pragma once

#include <string>

class Move
{
public:
  enum Direction
  {
    INVALID,
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

  Move(std::string input);
  int getCount() { return moveCount; }
  Direction getDirection() { return moveDirection; }
private:
  Move(Direction dir, unsigned short count);
  Direction charToDirection(char dir);

  Direction moveDirection = INVALID;
  unsigned short moveCount = 0;
};