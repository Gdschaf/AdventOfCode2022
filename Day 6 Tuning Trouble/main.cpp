#include <fstream>
#include <iostream>
#include <string>

#define ALPHABET_LENGTH 26
#define UNIQUE_LEGNTH 14 // 4 for part 1, 14 for part 2. 

int main(void)
{
  std::fstream file;
  file.open("input1.txt");
  if (file.is_open())
  {
    std::string line;
    std::getline(file, line); // literally just 1 line for the input on this one
    int letterArray[ALPHABET_LENGTH];
    memset(letterArray, 0, ALPHABET_LENGTH * sizeof(int));
    int numberOfDuplicates = 0;
    for (int i = 0; i < line.size(); ++i)
    {
      // remove the furthest away letter
      if (i >= UNIQUE_LEGNTH)
      {
        int removeLetterIndex = line[i - UNIQUE_LEGNTH] - 'a';
        --letterArray[removeLetterIndex];
        if (letterArray[removeLetterIndex] == 1) // this was a duplicate letter, it is no more.
          --numberOfDuplicates;
      }

      // we need to find the first index where the last UNIQUE_LEGNTH letters are unique.
      int letterIndex = line[i] - 'a';
      ++letterArray[letterIndex];
      if (letterArray[letterIndex] == 2)
        ++numberOfDuplicates;

      // DEUBUGGING
      // if (i >= UNIQUE_LEGNTH)
      // {
      //   std::cout << line.substr(i - UNIQUE_LEGNTH + 1, UNIQUE_LEGNTH) << " \t Number of duplicates: " << numberOfDuplicates << std::endl;
      // }

      if (i >= UNIQUE_LEGNTH && numberOfDuplicates == 0)
      {
        std::cout << "The first index where the last " << UNIQUE_LEGNTH << " letters were unique was: " << i << " \t (Which is letter " << (i + 1) << ")" << std::endl;
        break;
      }
    }
    file.close();
  }
}