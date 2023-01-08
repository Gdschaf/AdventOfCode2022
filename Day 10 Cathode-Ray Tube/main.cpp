#include <fstream>
#include <iostream>

#include "Operation.h"
#include "StringHelper.h"

#define DELIMITER ' '

int main(void)
{
  std::fstream file;
  file.open("input.txt");
  // file.open("test.txt");
  if (file.is_open())
  {
    std::string line;
    std::vector<Operation> operationList = std::vector<Operation>();
    while (std::getline(file, line))
    {
      if (!line.empty())
      {
        std::vector<std::string> splitInput = split(line, DELIMITER);
        if (splitInput.size() == 1) // noop
        {
          operationList.push_back(Operation());
        }
        else // addx 17
        {
          operationList.push_back(Operation(2, std::stoi(splitInput[1])));
        }
      }
    }
    file.close();

    int x = 1;
    int cycleCount = 0;
    int sum = 0;
    while (operationList.size() > 0)
    {
      ++cycleCount;
      --operationList[0].cycles;

      //20th, 60th, 100th, 140th, 180th, and 220th cycles
      if (cycleCount == 20 || cycleCount == 60 || cycleCount == 100 || cycleCount == 140 || cycleCount == 180 || cycleCount == 220)
      {
        int multiplied = cycleCount * x;
        sum += multiplied;
        // std::cout << "The value of x is " << x << " after " << cycleCount << " number of cycles, adding a total of " << multiplied << " to the sum." << std::endl;
      }

      int pos = (cycleCount - 1) % 40;
      if (pos == 0)
        std::cout << std::endl;
      if (pos >= x - 1 && pos <= x + 1)
        std::cout << "#";
      else
        std::cout << ".";

      // std::cout << "Cycle " << cycleCount << " ";
      if (operationList[0].cycles == 0) 
      {
        int value = operationList[0].value;
        // if (value == 0)
        // {
        //   std::cout << "Removing noop";
        // }
        // else
        // {
        //   std::cout << "Removing addx, adding " << value;
        // }
        x += value;
        operationList.erase(operationList.begin());
      }
      // std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "The sum of x after the 6 iterations is " << sum << std::endl;
  }
}