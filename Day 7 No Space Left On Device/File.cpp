#include <sstream>

#include "File.h"

File::File(long fileSize, std::string fileName, Node* parent) : Node(parent, Node::FILE), size(fileSize), name(fileName) { }

long File::getSize()
{
  return size;
}

std::string File::print()
{
  std::stringstream ss;
  ss << "File name: \"" << name << "\" - Size: " << size;
  return ss.str();
}
