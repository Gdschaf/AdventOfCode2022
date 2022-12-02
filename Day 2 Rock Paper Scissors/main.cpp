#include <fstream>
#include <iostream>
#include <vector>

#include "RockPaperScissorInput.h"

int main(void) {
  std::fstream file;

  file.open("input1.txt");
  if (file.is_open())
  {
    std::string line;
    std::vector<RockPaperScissorInput> playedGames = std::vector<RockPaperScissorInput>();
    while (std::getline(file, line)) 
    {
      if (!line.empty())
      {
        playedGames.push_back(RockPaperScissorInput(line));
      }
    }
    file.close();

    long totalScore = 0;
    std::vector<RockPaperScissorInput>::iterator itEnd = playedGames.end();
    for (std::vector<RockPaperScissorInput>::iterator it = playedGames.begin(); it != itEnd; ++it)
    {
      totalScore += it->getScore();
    }

    std::cout << "The total score after " << playedGames.size() << " games is " << totalScore << std::endl;
  }
}