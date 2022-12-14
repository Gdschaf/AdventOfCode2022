#pragma once

class Position
{
public:
  Position(int x, int y) : first(x), second(y) { }
  bool operator==(const Position& rhs) const;
  int first, second;
};