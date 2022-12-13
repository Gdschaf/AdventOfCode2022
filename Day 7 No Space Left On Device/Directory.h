#pragma once

#include <vector>

#include "Node.h"

#define MAX_SIZE 100000

#define FILESYSTEM_SIZE 70000000
#define UPDATE_SIZE 30000000

typedef std::vector<Node*> NodeList;

class Directory : Node
{
public:
  Directory(std::string dirName, Node* parent);
  void addContent(Node* node);
  Node* findDirectory(std::string dirName);
  Node* findFile(std::string fileName);
  long partOne();
  long partTwo(long clearSize);
  std::string getName() { return directoryName; }
  long getSize() override;
  std::string print() override;
private:
  std::string directoryName;
  NodeList contents = NodeList();
};