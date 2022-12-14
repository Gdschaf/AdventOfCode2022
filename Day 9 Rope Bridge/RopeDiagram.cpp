#include <iostream>

#include "RopeDiagram.h"

RopeDiagram::RopeDiagram()
{
  for (int i = 0; i < SNAKE_LENGTH; ++i)
  {
    snake.push_back(Position(0, 0));
  }
  tailVisitedPositions.push_back(Position(0, 0));
}

void RopeDiagram::doMove(Move::Direction direction)
{
  moveHead(direction);
  for (int i = 1; i < snake.size(); ++i)
  {
    if (knotNeedsToFollow(snake[i - 1], snake[i]))
    {
      Position closestPosition = closestMove(snake[i - 1], snake[i]);
      snake[i].first = closestPosition.first;
      snake[i].second = closestPosition.second;
      if (i == snake.size() - 1)
      {
        addUnique(snake[i]);
        std::cout << "Tail moved to (" << snake[i].first << ", " << snake[i].second << ")" << std::endl;
      }
    }
    else
      break;
  }
}

int RopeDiagram::getTailVisitedPositions()
{
  return tailVisitedPositions.size(); // should be this easy
}

void RopeDiagram::moveHead(Move::Direction direction)
{
  switch (direction)
  {
  case Move::UP:
    ++snake[0].second;
    break;
  case Move::DOWN:
    --snake[0].second;
    break;
  case Move::LEFT:
    --snake[0].first;
    break;
  case Move::RIGHT:
    ++snake[0].first;
    break;
  case Move::INVALID:
    std::cout << "Invalid move was passed in." << std::endl;
    break;
  }
}

void RopeDiagram::addUnique(Position p)
{
  std::list<Position>::iterator itEnd = tailVisitedPositions.end();
  for (std::list<Position>::iterator it = tailVisitedPositions.begin(); it != itEnd; ++it)
  {
    if (it->first == p.first && it->second == p.second)
      return;
  }
  tailVisitedPositions.push_back(p);
}

bool RopeDiagram::knotNeedsToFollow(Position head, Position tail)
{
  return std::abs(head.first - tail.first) > 1 || std::abs(head.second - tail.second) > 1;
}

Position RopeDiagram::closestMove(Position head, Position tail)
{
  int distance = 5;
  Position closest = Position(0, 0);
  for (int i = -1; i <= 1; ++i)
  {
    for (int j = -1; j <= 1; ++j)
    {
      if (j == 0 && i == 0)
        continue;
      Position p = Position(tail.first + i, tail.second + j);
      int tempDistance = std::abs(p.first - head.first) + std::abs(p.second - head.second);
      if (tempDistance < distance)
      {
        closest.first = p.first;
        closest.second = p.second;
        distance = tempDistance;
      }
    }
  }
  return closest;
}
