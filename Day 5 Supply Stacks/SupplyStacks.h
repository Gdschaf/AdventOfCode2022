#pragma once

#include <vector>
#include <stack>
#include <ostream>

#include "Move.h"

typedef std::vector<std::stack<char>> StackList;

class SupplyStacks
{
public:
  void initializeStacks(std::string input);
  void addRow(std::string input);
  void applyMove(Move move);
  std::string getTopCrates();
private:
  StackList stacks = StackList();
};