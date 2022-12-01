#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define TOP_COUNT_NUMBER 3

int main(void) 
{
  std::fstream file;

  file.open("input1.txt");
  if (file.is_open()) 
  {
    std::string line;
    std::vector<long> elfsCalorieCount = std::vector<long>();

    long currentCount = 0;
    long highestCount = 0;
    while (std::getline(file, line)) 
    {
      if (line.empty()) 
      {
        elfsCalorieCount.push_back(currentCount);
        if (currentCount > highestCount) 
        {
          highestCount = currentCount;
        }
        currentCount = 0;
      }
      else 
      {
        currentCount += std::stol(line);
      }
    }
    file.close();

    //print out results here

    //answer 1
    std::cout << "The highest calories count elf has " << highestCount << " calories." << std::endl;

    //answer 2
    long topXCount = 0;
    int numberOfElves = elfsCalorieCount.size();
    std::sort(elfsCalorieCount.begin(), elfsCalorieCount.end());
    if (elfsCalorieCount.size() >= TOP_COUNT_NUMBER)
    {
      for (int i = numberOfElves - 1; i > (numberOfElves - 1 - TOP_COUNT_NUMBER); --i)
      {
        topXCount += elfsCalorieCount[i];
      }
      std::cout << "The top " << TOP_COUNT_NUMBER << " elves are carrying a total of " << topXCount << " calories." << std::endl;
    }
    else 
    {
      std::cout << "There's only " << numberOfElves << " number of elves, this doesn't make sense." << std::endl;
    }
  }
}