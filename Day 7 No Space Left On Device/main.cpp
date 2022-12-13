#include <fstream>
#include <iostream>

#include "FileSystem.h"
#include "StringHelper.h"

#define INPUT_CHAR '$'
#define SPLIT_CHAR ' '

#define CHANGE_DIRECTORY "cd"
#define LIST_CONTENTS "ls"
#define DIRECTORY_PREFIX "dir"

int main(void)
{
  std::fstream file;
  file.open("input.txt");
  if (file.is_open())
  {
    std::string line;
    FileSystem fs = FileSystem();
    bool listingContents = false;
    while (std::getline(file, line))
    {
      if (!line.empty()) 
      {
        std::vector<std::string> input = split(line, SPLIT_CHAR);
        if (line[0] == INPUT_CHAR) // This is the user input
        {
          listingContents = false;
          if (input[1] == CHANGE_DIRECTORY)
          {
            fs.cd(input[2]);
          }
          else if (input[1] == LIST_CONTENTS)
          {
            listingContents = true;
          }
        }
        else if (listingContents)
        {
          if (input[0] == DIRECTORY_PREFIX)
          {
            fs.addDir(input[1]);
          }
          else
          {
            fs.addFile(std::stol(input[0]), input[1]);
          }
        }
      }
    }

    long totalSize = fs.partOne();
    std::cout << "Total sum of directories with a size of at most " << MAX_SIZE << " is: " << totalSize << std::endl;

    std::cout << "The total size of the root is: " << fs.getSize() << std::endl;
    std::cout << "The smallest directory we can clear is: " << fs.partTwo() << std::endl;
    file.close();
  }
}