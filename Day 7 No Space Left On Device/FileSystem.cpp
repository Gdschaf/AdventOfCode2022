#include <iostream>

#include "FileSystem.h"

#define ROOT_DIR "/"
#define UP_LEVEL ".."

void FileSystem::cd(std::string dirName)
{
  if (root == nullptr)
  {
    // create the root node;
    Directory* newDir = new Directory(dirName, nullptr);
    root = (Node*)newDir;
    currentDirectory = root;
    std::cout << "Adding root (" << root->print() << ")" << std::endl;
  }
  else
  {
    if (currentDirectory->isDirectory())
    {
      Directory* dir = (Directory*)currentDirectory;
      Node* newDir = dir->findDirectory(dirName);
      if (newDir != nullptr)
      {
        currentDirectory = newDir;
        std::cout << "Going into directory (" << newDir->print() << ")" << std::endl;
      }
      else if (dirName == ROOT_DIR)
      {
        currentDirectory = root;
        std::cout << "Returning to root directory. (" << root->print() << ")" << std::endl;
      }
      else if (dirName == UP_LEVEL)
      {
        Node* parent = currentDirectory->getParent();
        if (parent != nullptr)
        {
          currentDirectory = parent;
          std::cout << "Going up a level to directory (" << parent->print() << ")" << std::endl;
        }
        else
          std::cout << "Already at root level, can't go any higher." << std::endl;
      }
    }
  }
}

void FileSystem::addDir(std::string dirName)
{
  if (currentDirectory->isDirectory())
  {
    Directory* dir = (Directory*)currentDirectory;
    if (dir->findDirectory(dirName) == nullptr)
    {
      dir->addContent((Node*)(new Directory(dirName, currentDirectory)));
    }
    else 
    {
      std::cout << "Directory named \"" << dirName << "\" already exists in directory \"" << dir->getName() << "\"." << std::endl;
    }
  }
}

void FileSystem::addFile(long fileSize, std::string fileName)
{
  if (currentDirectory->isDirectory())
  {
    Directory* dir = (Directory*)currentDirectory;
    dir->addContent((Node*)(new File(fileSize, fileName, currentDirectory)));
  }
}

long FileSystem::partOne()
{
  if (root->isDirectory())
  {
    Directory* dir = (Directory*)root;
    return dir->partOne();
  }
  return 0;
}

long FileSystem::partTwo()
{
  long rootSize = getSize();
  long freeSpace = FILESYSTEM_SIZE - rootSize;
  long clearSpace = UPDATE_SIZE - freeSpace;
  if (root->isDirectory() && freeSpace < UPDATE_SIZE)
  {
    std::cout << "Need to clear " << clearSpace << " to make " << UPDATE_SIZE << " space free." << std::endl;
    Directory* dir = (Directory*)root;
    return dir->partTwo(clearSpace);
  }
  return 0;
}

