#include "TreeGrid.h"

// Hey look, we're not just gonna leak a bunch of memory this time....
TreeGrid::~TreeGrid()
{
  Tree* currentRow = rootNode;
  if (currentRow != nullptr)
  {
    Tree* nextRow = currentRow->Down();
    while (currentRow != nullptr)
    {
      Tree* deleteThis = currentRow;
      currentRow = currentRow->Right();
      delete deleteThis;

      if (currentRow == nullptr)
      {
        currentRow = nextRow;
        if (currentRow != nullptr)
          nextRow = currentRow->Down();
      }
    }
  }
}

void TreeGrid::addRow(std::string input)
{
  Tree* newRow = constructRow(input);
  if (rootNode == nullptr)
    rootNode = newRow;
  else
  {
    Tree* lastRow = rootNode;
    while (lastRow->Down() != nullptr)
      lastRow = lastRow->Down();

    while (lastRow != nullptr && newRow != nullptr)
    {
      lastRow->setDown(newRow);
      newRow->setUp(lastRow);
      lastRow = lastRow->Right();
      newRow = newRow->Right();
    }
  }
}

int TreeGrid::getVisibleTreeCount()
{
  int visibleCount = 0;
  Tree* currentRow = rootNode;
  if (currentRow != nullptr)
  {
    Tree* nextRow = currentRow->Down();
    while (currentRow != nullptr)
    {
      if (currentRow->isVisible())
        ++visibleCount;
      currentRow = currentRow->Right();

      if (currentRow == nullptr)
      {
        currentRow = nextRow;
        if (currentRow != nullptr)
          nextRow = currentRow->Down();
      }
    }
  }
  return visibleCount;
}

int TreeGrid::getLargestScenicScore()
{
  int largestScenicScore = 0;
  Tree* currentRow = rootNode;
  if (currentRow != nullptr)
  {
    Tree* nextRow = currentRow->Down();
    while (currentRow != nullptr)
    {
      int scenicScore = currentRow->getScenicScore();
      largestScenicScore = scenicScore > largestScenicScore ? scenicScore : largestScenicScore;
      currentRow = currentRow->Right();

      if (currentRow == nullptr)
      {
        currentRow = nextRow;
        if (currentRow != nullptr)
          nextRow = currentRow->Down();
      }
    }
  }
  return largestScenicScore;
}

Tree* TreeGrid::constructRow(std::string input)
{
  Tree* root = nullptr;
  Tree* lastNode = nullptr;
  for (int i = 0; i < input.size(); ++i)
  {
    Tree* newNode = new Tree(input[i] - '0');
    if (root == nullptr)
    {
      root = newNode;
      lastNode = root;
    } 
    else
    {
      lastNode->setRight(newNode);
      newNode->setLeft(lastNode);
      lastNode = newNode;
    }
  }
  return root;
}

std::ostream& operator<<(std::ostream& os, const TreeGrid& rhs)
{
  Tree* currentRow = rhs.rootNode;
  if (currentRow != nullptr)
  {
    Tree* nextRow = currentRow->Down();
    while (currentRow != nullptr)
    {
      os << currentRow->getHeight();
      currentRow = currentRow->Right();

      if (currentRow == nullptr)
      {
        os << std::endl;
        currentRow = nextRow;
        if (currentRow != nullptr)
          nextRow = currentRow->Down();
      }
    }
  }
  return os;
}