#pragma once

#include <vector>
#include <string>

class Rucksack
{
public:
  Rucksack(std::string items);
  Rucksack(std::vector<std::string> itemsList) : compartments(itemsList) { }
  unsigned int getPriority();
private:
  std::vector<std::string> compartments = std::vector<std::string>();
  char getCommonItem();

  static unsigned int getItemPriority(char item);
};