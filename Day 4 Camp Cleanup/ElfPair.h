#pragma once

#include "SectionAssignment.h"

class ElfPair
{
public:
  ElfPair(std::string input);
  bool fullyOverlap();
  bool partiallyOverlap();
private:
  std::vector<SectionAssignment> assignedSections = std::vector<SectionAssignment>();
};