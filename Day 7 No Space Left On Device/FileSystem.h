#pragma once

#include "File.h"
#include "Directory.h"

class FileSystem
{
public:
  void cd(std::string dirName);
  void addDir(std::string dirName);
  void addFile(long fileSize, std::string fileName);
  long getSize() { return root->getSize(); }

  long partOne();
  long partTwo();
private:
  Node* root = nullptr;
  Node* currentDirectory = nullptr;
};