#include "Tree.h"

Tree::Tree(unsigned short h) : height(h) { }

unsigned short Tree::getHeight() const
{
  return height;
}

bool Tree::isVisible()
{
  if(visibleSet)
    return visible;

  // check up down left right here, could do recursive functions, that'd be easy
  // if my memory serves me right, if one of these is true, we don't continue with the remaining calls
  visible = visibleUp(height) || visibleDown(height) || visibleLeft(height) || visibleRight(height);

  return visible;
}

int Tree::getScenicScore()
{
  if (scenicScoreCalculated)
    return scenicScore;

  scenicScore = scenicScoreUp(height) * scenicScoreDown(height) * scenicScoreLeft(height) * scenicScoreRight(height);
  return scenicScore;
}