#pragma once

#include <string>

class Node
{
public:

  enum Type
  {
    FILE,
    DIRECTORY
  };

  Node(Node * parent, Type type) : p(parent), nodeType(type) { }
  bool isFile() { return nodeType == FILE; }
  bool isDirectory() { return nodeType == DIRECTORY; }
  Node* getParent() { return p; }
  virtual long getSize() = 0;
  virtual std::string print() = 0;
private:
  Node* p;
  Type nodeType;
};