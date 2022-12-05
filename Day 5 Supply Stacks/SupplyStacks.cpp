#include "SupplyStacks.h"
#include "StringHelper.h"

#include <iostream>

#define DELIMITER ' '

void SupplyStacks::initializeStacks(std::string input)
{
  //using the row with just the numbers in it, create the number of stacks
  //example: [ 1   2   3   4   5   6   7   8   9 ]
  std::vector<std::string> splitString = split(input, ' ');
  int stackCount = std::stoi(splitString[splitString.size() - 1]);
  for (int i = 0; i < stackCount; ++i)
  {
    stacks.push_back(std::stack<char>());
  }
}

void SupplyStacks::addRow(std::string input)
{
  // row by row, add the values to their appropriate stacks
  // [Q]         [N]             [N]
  // [H]     [B] [D]             [S] [M]
  // [C]     [Q] [J]         [V] [Q] [D]
  // [T]     [S] [Z] [F]     [J] [J] [W]
  // [N] [G] [T] [S] [V]     [B] [C] [C]
  // [S] [B] [R] [W] [D] [J] [Q] [R] [Q] -> etc.
  // [V] [D] [W] [G] [P] [W] [N] [T] [S] -> 2nd
  // [B] [W] [F] [L] [M] [F] [L] [G] [J] -> 1st
  //  1   5   9   13  17  21  25  29  34
  
  for (int stringIndex = 1, stackIndex = 0; stringIndex < input.size(); stringIndex += 4, ++stackIndex)
  {
    if (input[stringIndex] >= 'A' && input[stringIndex] <= 'Z')
      stacks[stackIndex].push(input[stringIndex]);
  }
}

void SupplyStacks::applyMove(Move move)
{
  int to = move.To(), from = move.From(), stackCount = stacks.size();
  if (to >= stackCount || from >= stackCount)
  {
    std::cout << "Either the to (" << to << ") index or the from (" << from << ") index is out of stacks range (" << stackCount << ")." << std::endl;
    return;
  }

  std::stack<char> tempStack = std::stack<char>();
  for (int i = 0; i < move.Count(); ++i)
  {
    if (stacks[from].empty())
    {
      std::cout << "There are no more crates to move off of stack " << from << ". We moved " << i << " creates and were planning on moving " << (move.Count() - i) << " more creates." << std::endl;
      return;
    }

    // part 2
    tempStack.push(stacks[from].top());
    stacks[from].pop();

    // part 1
    // stacks[to].push(stacks[from].top());
    // stacks[from].pop();
  }

  // also part 2
  while (!tempStack.empty())
  {
    stacks[to].push(tempStack.top());
    tempStack.pop();
  }
}

std::string SupplyStacks::getTopCrates()
{
  std::string returnString;
  StackList::iterator itEnd = stacks.end();
  for (StackList::iterator it = stacks.begin(); it != itEnd; ++it)
  {
    returnString.push_back(it->top());
  }
  return returnString;
}