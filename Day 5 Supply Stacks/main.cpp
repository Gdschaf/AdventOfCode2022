#include <fstream>
#include <iostream>

#include "SupplyStacks.h"

int main(void)
{
  std::fstream file;
  file.open("input1.txt");
  if (file.is_open())
  {
    // we're gonna need to figure out how to parse the initial supply stacks
    std::string line;
    bool moveInput = false;
    SupplyStacks supplyStacks = SupplyStacks();
    std::vector<std::string> stackInput = std::vector<std::string>();
    while (std::getline(file, line))
    {
      if (line.empty())
      {
        moveInput = true;

        supplyStacks.initializeStacks(stackInput[stackInput.size() - 1]);
        for (int i = stackInput.size() - 2; i >= 0; --i)
        {
          supplyStacks.addRow(stackInput[i]);
        }

        continue;
      }

      if (moveInput)
      {
        supplyStacks.applyMove(Move(line));
      }
      else
      {
        stackInput.push_back(line);
      }
    }

    std::cout << "The top of the stacks after all the moves is \"" << supplyStacks.getTopCrates() << "\"." << std::endl;

    file.close();
  }
}