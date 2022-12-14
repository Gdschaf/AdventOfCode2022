#pragma once

#include <list>
#include <vector>

#include "Move.h"
#include "Position.h"

#define SNAKE_LENGTH 10

class RopeDiagram
{
public:
  RopeDiagram();
  void doMove(Move::Direction direction);
  int getTailVisitedPositions();
  std::vector<Position> getSnake() { return snake; }
private:
  void moveHead(Move::Direction direction);
  void addUnique(Position p);
  bool knotNeedsToFollow(Position head, Position tail);
  Position closestMove(Position head, Position tail);

  std::vector<Position> snake = std::vector<Position>();
  std::list<Position> tailVisitedPositions = std::list<Position>();
};