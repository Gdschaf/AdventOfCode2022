#include "ElfPair.h"

#define DELIMITER ','

ElfPair::ElfPair(std::string input)
{
  // split input with DELIMITER
  // push section assignment of [0] and [1] onto assignedSections
  std::vector<std::string> ranges = split(input, DELIMITER);
  std::vector<std::string>::iterator itEnd = ranges.end();
  for (std::vector<std::string>::iterator it = ranges.begin(); it != itEnd; ++it)
  {
    assignedSections.push_back(SectionAssignment(*it));
  }
}

// This is assuming we only need 1 assignment range to be inside any 1 other assignment range.
// For part 1, there's only 2 assignments per pair, which makes sense, but leaving this open for part 2
bool ElfPair::fullyOverlap()
{
  for (int i = 0; i < assignedSections.size(); ++i)
  {
    for (int j = 0; j < assignedSections.size(); ++j)
    {
      if (i == j)
        continue;
      if (assignedSections[i].inRange(assignedSections[j]))
        return true;
    }
  }
  return false;
}

bool ElfPair::partiallyOverlap()
{
  // I believe this is redundant, but alas, copy pasta.
  for (int i = 0; i < assignedSections.size(); ++i)
  {
    for (int j = 0; j < assignedSections.size(); ++j)
    {
      if (i == j)
        continue;
      if (assignedSections[i].overlap(assignedSections[j]))
        return true;
    }
  }
  return false;
}
