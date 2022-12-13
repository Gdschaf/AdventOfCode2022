#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Tree.h"

class TreeGrid
{
public:
  ~TreeGrid();
  void addRow(std::string input);
  int getVisibleTreeCount();
  int getLargestScenicScore();
  friend std::ostream& operator<<(std::ostream& os, const TreeGrid& rhs);
private:
  Tree* constructRow(std::string input);
  Tree* rootNode = nullptr;
};