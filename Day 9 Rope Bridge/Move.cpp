#include "Move.h"
#include "StringHelper.h"

#define DELIMITER ' '

Move::Move(std::string input)
{
  std::vector<std::string> splitString = split(input, DELIMITER);
  moveDirection = charToDirection(splitString[0][0]);
  moveCount = std::stoi(splitString[1]);
}

Move::Move(Direction dir, unsigned short count) : moveDirection(dir), moveCount(count) { }

Move::Direction Move::charToDirection(char dir)
{
  switch (dir)
  {
    case 'U':
      return UP;
    case 'D':
      return DOWN;
    case 'L':
      return LEFT;
    case 'R':
      return RIGHT;
    default:
      return INVALID;
  }
}
