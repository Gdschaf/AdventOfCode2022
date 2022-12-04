#include <unordered_map>
#include <iostream>

#include "Rucksack.h"

Rucksack::Rucksack(std::string items)
{
  unsigned int halfCount = items.size() / 2; //in my testing, this is always an even number.
  compartments.push_back(items.substr(0, halfCount));
  compartments.push_back(items.substr(halfCount, halfCount));
}

unsigned int Rucksack::getPriority()
{
  char c = getCommonItem();
  int priority = getItemPriority(c);
  std::cout << c << "\t" << priority << std::endl;
  // return getItemPriority(getCommonItem());
  return priority;
}

char Rucksack::getCommonItem()
{
  std::unordered_map<char, int> itemMap = std::unordered_map<char, int>();
  std::cout << compartments.size() << "\t";
  for (int c = 0; c < compartments.size(); ++c)
  {
    std::cout << compartments[c] << "\t";
    for (int i = 0; i < compartments[c].size(); ++i)
    {
      int currentCount = itemMap[compartments[c][i]];
      if (currentCount == c)
      {
        ++itemMap[compartments[c][i]];
        if (itemMap[compartments[c][i]] == compartments.size())
          return compartments[c][i];
      }
    }
  }
  return 0;
}

unsigned int Rucksack::getItemPriority(char item)
{
  if (item >= 'a' && item <= 'z')
    return item - 'a' + 1;
  if (item >= 'A' && item <= 'Z')
    return item - 'A' + 27;
}
