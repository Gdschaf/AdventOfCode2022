#include "Move.h"

#include <iostream>

Move::Move(std::string input)
{
  // example input
  // move 11 from 7 to 2
  int result = sscanf_s(input.c_str(), "move %d from %d to %d", &moveCount, &fromIndex, &toIndex);

  // from 1 based to 0 based indexes
  --fromIndex;
  --toIndex;

  if (result != 3)
    std::cout << "There was an error reading the values for \"" << input << "\". It was only able to fill " << result << " variables." << std::endl;
}
