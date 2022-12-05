#pragma once

#include "StringHelper.h"

class SectionAssignment
{
public:
  SectionAssignment(int start, int end);
  SectionAssignment(std::string input);
  bool inRange(SectionAssignment& rhs);
  bool overlap(SectionAssignment& rhs);
private:
  int startRange, endRange;
};