#include <algorithm>

class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    std::vector<std::vector<int> > minPath;
    for (auto iter = grid.begin(); iter != grid.end(); ++iter)
    {
      std::vector<int> temp;
      for (auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
        temp.push_back(0);
      minPath.push_back(temp);
    }

    minPath[0][0] = grid[0][0];

    for (size_t i = 1; i != grid.size(); ++i)
      minPath[i][0] = minPath[i-1][0] + grid[i][0];

    for (size_t i = 1; i != grid[0].size(); ++i)
      minPath[0][i] = minPath[0][i-1] + grid[0][i];

    for (size_t i = 1; i != grid.size(); ++i)
    {
      for (size_t j = 1; j != grid[i].size(); ++j)
      {
        minPath[i][j] = std::min(minPath[i-1][j], minPath[i][j-1]) + grid[i][j];
      }
    }

    return minPath.back().back();
  }
};
