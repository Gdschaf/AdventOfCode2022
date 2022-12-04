#include <fstream>
#include <iostream>

#include "Rucksack.h"

// #define PART_ONE
#define PART_TWO

#define GROUP_SIZE 3

int main(void) {
  std::fstream file;
  file.open("input1.txt");
  //file.open("testInput.txt");
  if (file.is_open())
  {
    std::string line;
    std::vector<Rucksack> rucksacks = std::vector<Rucksack>();
    std::vector<std::string> groupList = std::vector<std::string>();
    while (std::getline(file, line))
    {
      if (!line.empty())
      {
#ifdef PART_ONE
        rucksacks.push_back(Rucksack(line));
#endif

#ifdef PART_TWO
        groupList.push_back(line);
        if (groupList.size() == GROUP_SIZE)
        {
          rucksacks.push_back(Rucksack(groupList));
          groupList.clear();
        }
#endif
      }
    }

    file.close();

    long totalPriority = 0;
    for (int i = 0; i < rucksacks.size(); ++i)
    {
      totalPriority += rucksacks[i].getPriority();
    }

    std::cout << "The total sum of the priorities is " << totalPriority << std::endl;
  }
}