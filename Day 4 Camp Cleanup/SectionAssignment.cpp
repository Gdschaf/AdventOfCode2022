#include "SectionAssignment.h"

#define DELIMITER '-'

SectionAssignment::SectionAssignment(int start, int end) : startRange(start), endRange(end) { }

SectionAssignment::SectionAssignment(std::string input)
{
  // split input with DELIMITER
  // [0] is start integer, [1] is end integer
  std::vector<std::string> splitInput = split(input, DELIMITER);
  startRange = std::stoi(splitInput[0]);
  endRange = std::stoi(splitInput[1]);
}

bool SectionAssignment::inRange(SectionAssignment& rhs)
{
  return startRange >= rhs.startRange && endRange <= rhs.endRange;
}

bool SectionAssignment::overlap(SectionAssignment& rhs)
{
  return startRange <= rhs.endRange && endRange >= rhs.startRange;
}
