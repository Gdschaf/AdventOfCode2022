#include "StringHelper.h"

std::vector<std::string> split(std::string input, char delimiter)
{
  std::vector<std::string> splitString = std::vector<std::string>();
  int stringSize = input.size();

  int stringStart = 0;
  for (int i = 0; i < stringSize; ++i)
  {
    if (input[i] == delimiter)
    {
      if (i == stringStart) // for the case where it's 12--67, double delimiter
      {
        ++stringStart;
        continue;
      }
      splitString.push_back(input.substr(stringStart, i - stringStart));
      stringStart = i + 1;
    }
  }
  if (stringSize - stringStart > 0) // this handles "12-"
    splitString.push_back(input.substr(stringStart, stringSize - stringStart));

  return splitString;
}