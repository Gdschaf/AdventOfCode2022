#pragma once

#define Direction(FunctionName, Direction) void set ## FunctionName(Tree* Direction) { surroundingTrees.Direction = Direction; } \
                                           Tree* FunctionName() { return surroundingTrees.Direction; }

#define RecursiveChecks(FunctionName, Direction) bool visible ## FunctionName(unsigned short height) \
                                                 { \
                                                   if (surroundingTrees.Direction == nullptr) \
                                                     return true; \
                                                   return height > surroundingTrees.Direction->height && surroundingTrees.Direction->visible ## FunctionName(height); \
                                                 }

#define RecursiveScenicScore(FunctionName, Direction) int scenicScore ## FunctionName(unsigned short height) \
                                                      { \
                                                        if (surroundingTrees.Direction == nullptr) \
                                                          return 0; \
                                                        if (height > surroundingTrees.Direction->height) \
                                                          return 1 + surroundingTrees.Direction->scenicScore ## FunctionName(height); \
                                                        return 1; \
                                                      }

class Tree
{
public:
  Tree(unsigned short h);
  unsigned short getHeight() const;
  bool isVisible();
  int getScenicScore();

  Direction(Up, up)
  Direction(Down, down)
  Direction(Left, left)
  Direction(Right, right)

  struct Directions
  {
    Tree* up = nullptr;
    Tree* down = nullptr;
    Tree* left = nullptr;
    Tree* right = nullptr;
  };

private:
  unsigned short height;
  bool visibleSet = false;
  bool visible = false;
  bool scenicScoreCalculated = false;
  int scenicScore = 0;
  Directions surroundingTrees = Directions();

  RecursiveChecks(Up, up)
  RecursiveChecks(Down, down)
  RecursiveChecks(Left, left)
  RecursiveChecks(Right, right)

  RecursiveScenicScore(Up, up)
  RecursiveScenicScore(Down, down)
  RecursiveScenicScore(Left, left)
  RecursiveScenicScore(Right, right)
};