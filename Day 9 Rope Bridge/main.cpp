#include <fstream>
#include <iostream>
#include <conio.h>

#include "RopeDiagram.h"

std::string directionString(Move::Direction dir)
{
  switch (dir)
  {
  case Move::DOWN:
    return "Down";
    break;
  case Move::LEFT:
    return "Left";
    break;
  case Move::RIGHT:
    return "Right";
    break;
  case Move::UP:
    return "Up";
    break;
  default:
    return "";
    break;
  }
}

//x -11 -> 14 -> size = 26
//y -5 -> 15 -> size = 21
//offset is x = 11, y = 5

typedef std::vector<char> Column;
typedef std::vector<Column> Board;

// good for testing partTwo.txt, some numbers can be changed to debug others
void printDebug(std::vector<Position> snake, Move::Direction dir)
{
  Board b = Board();
  for (int x = 0; x < 26; ++x)
  {
    Column c = Column();
    for (int y = 0; y < 21; ++y)
    {
      c.push_back('.');
    }
    b.push_back(c);
  }

  for (int i = 0; i < snake.size(); ++i)
  {
    b[snake[i].first + 11][snake[i].second + 5] = i == 0 ? 'H' : i + '0';
  }
  
  std::cout << directionString(dir) << std::endl;
  for (int y = 20; y >= 0; --y)
  {
    for (int x = 0; x < 26; ++x)
    {
      std::cout << b[x][y] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;      
}

int main()
{
  std::fstream file;
  file.open("input.txt");
  // file.open("simple.txt");
  // file.open("partTwo.txt");
  if (file.is_open())
  {
      std::string line;
      std::vector<Move> listOfMoves = std::vector<Move>();
      while (std::getline(file, line))
      {
          if (!line.empty())
          {
              listOfMoves.push_back(Move(line));
          }
      }
      file.close();

      RopeDiagram diagram = RopeDiagram();
      std::vector<Move>::iterator itEnd = listOfMoves.end();
      for (std::vector<Move>::iterator it = listOfMoves.begin(); it != itEnd; ++it)
      {
          for (int i = 0; i < it->getCount(); ++i)
          {
              diagram.doMove(it->getDirection());
              // printDebug(diagram.getSnake(), it->getDirection());
              // _getch();
          }
      }
      
      int tailSpotCount = diagram.getTailVisitedPositions();
      std::cout << "The tail of the rope visited " << tailSpotCount << " number of positions." << std::endl;
  }
}
