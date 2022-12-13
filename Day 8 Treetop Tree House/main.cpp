#include <fstream>

#include "TreeGrid.h"

int main(void)
{
  std::fstream file;
  file.open("input.txt");
  if (file.is_open())
  {
    std::string line;
    TreeGrid treeGrid = TreeGrid();
    while (std::getline(file, line))
    {
      if (!line.empty())
      {
        treeGrid.addRow(line);
      }
    }
    std::cout << treeGrid; // oh hey, it's working
    int visibleTrees = treeGrid.getVisibleTreeCount();
    std::cout << "There are " << visibleTrees << " number of visible trees." << std::endl;

    int scenicScore = treeGrid.getLargestScenicScore();
    std::cout << "The tree with the largest scenic score has a score of: " << scenicScore << std::endl;
  }
}