#include <vector>
#include <cstdio>

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid) {
    std::vector<std::vector<int> > paths;
    for (size_t i = 0; i != obstacleGrid.size(); ++i)
    {
      std::vector<int> line;
      for (size_t j = 0; j != obstacleGrid[i].size(); ++j)
        line.push_back(0);
      paths.push_back(line);
    }

    paths[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (size_t i = 1; i != obstacleGrid.size(); ++i)
    {
      if (obstacleGrid[i][0])
        paths[i][0] = 0;
      else
        paths[i][0] = paths[i - 1][0];
    }
    for (size_t i = 1; i != obstacleGrid[0].size(); ++i)
    {
      if (obstacleGrid[0][i])
        paths[0][i] = 0;
      else
        paths[0][i] = paths[0][i - 1];
    }

    for (size_t i = 1; i != obstacleGrid.size(); ++i)
    {
      for (size_t j = 1; j != obstacleGrid[i].size(); ++j)
      {
        paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
        if (obstacleGrid[i][j])
          paths[i][j] = 0;
      }
    }

    return paths.back().back();
  }
};

int main(int argc, char* argv[])
{
  int m, n;
  scanf("%d%d", &m, &n);

  std::vector<std::vector<int> > ob;
  for (int i = 0; i < m; ++i)
  {
    std::vector<int> num;
    for (int j = 0; j < n; ++j)
    {
      int temp;
      scanf("%d", &temp);
      num.push_back(temp);
    }
    ob.push_back(num);
  }

  Solution s;
  printf("%d\n", s.uniquePathsWithObstacles(ob));

  return 0;
}

