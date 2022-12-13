#include <sstream>
#include <iostream>

#include "Directory.h"
#include "File.h"

Directory::Directory(std::string dirName, Node* parent) : Node(parent, Node::DIRECTORY), directoryName(dirName) { }

Directory::~Directory()
{
  NodeList::iterator itEnd = contents.end();
  for (NodeList::iterator it = contents.begin(); it != itEnd; ++it)
  {
    delete (*it);
  }
}

void Directory::addContent(Node* node)
{
  // duplicates are checked by the file system, not the directory.
  // might wanna change that? but we should allow directory and files that are named the same
  contents.push_back(node);
  std::cout << "Adding content (" << node->print() << ") to (" << this->print() << ")" << std::endl << std::endl;
}

Node* Directory::findDirectory(std::string dirName)
{
  NodeList::iterator itEnd = contents.end();
  for (NodeList::iterator it = contents.begin(); it != itEnd; ++it)
  {
    if ((*it)->isDirectory())
    {
      Directory* dir = (Directory*)(*it);
      if (dir->getName() == dirName)
        return (Node*)dir;
    }
  }
  return nullptr;
}

Node* Directory::findFile(std::string fileName)
{
  NodeList::iterator itEnd = contents.end();
  for (NodeList::iterator it = contents.begin(); it != itEnd; ++it)
  {
    if ((*it)->isFile())
    {
      File* file = (File*)(*it);
      if (file->getName() == fileName)
        return (Node*)file;
    }
  }
  return nullptr;
}

long Directory::partOne()
{
  long total = 0;
  long size = getSize();
  if (size <= MAX_SIZE)
    total += size;

  NodeList::iterator itEnd = contents.end(); 
  for (NodeList::iterator it = contents.begin(); it != itEnd; ++it)
  {
    if ((*it)->isDirectory())
    {
      Directory* dir = (Directory*)(*it);
      total += dir->partOne();
    }
  }

  return total;
}

long Directory::partTwo(long clearSize)
{
  long minimum = LONG_MAX;
  long size = getSize();
  if (size >= clearSize)
    minimum = size;

  NodeList::iterator itEnd = contents.end();
  for (NodeList::iterator it = contents.begin(); it != itEnd; ++it)
  {
    if ((*it)->isDirectory())
    {
      Directory* dir = (Directory*)(*it);
      long dirSize = dir->partTwo(clearSize);
      std::cout << "Size of directory: " << dir->print() << std::endl;
      if (dirSize >= clearSize && dirSize < minimum)
        minimum = dirSize;
    }
  }

  return minimum;
}

long Directory::getSize()
{
  long totalSize = 0;
  NodeList::iterator itEnd = contents.end();
  for (NodeList::iterator it = contents.begin(); it != itEnd; ++it)
  {
    totalSize += (*it)->getSize();
  }
  return totalSize;
}

std::string Directory::print()
{
  std::stringstream ss;
  ss << "Directory \"" << directoryName << "\" - Number of Contents: " << contents.size() << " - Size: " << getSize();
  return ss.str();
}
