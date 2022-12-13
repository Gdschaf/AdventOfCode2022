#pragma once

#include "Node.h"

class File : Node
{
public:
  File(long fileSize, std::string fileName, Node* parent);
  std::string getName() { return name; }
  long getSize();
  std::string print();
private:
  std::string name;
  long size;
};