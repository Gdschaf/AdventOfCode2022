#include <fstream>
#include <iostream>

#include "ElfPair.h"

int main(void)
{
  std::fstream file;
  file.open("input1.txt");
  if (file.is_open())
  {
    std::string line;
    int fullyOverlapCount = 0;
    int partiallyOverlapCount = 0;
    while (std::getline(file, line))
    {
      ElfPair p = ElfPair(line);
      if (p.fullyOverlap())
        ++fullyOverlapCount;
      if (p.partiallyOverlap())
        ++partiallyOverlapCount;
    }
    file.close();

    std::cout << "There are a total of " << fullyOverlapCount << " pairs with ranges that fully overlap and " << partiallyOverlapCount << " pairs that at least partially overlap." << std::endl;


  }
}