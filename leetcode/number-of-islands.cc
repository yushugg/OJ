#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  void DFS(vector<vector<char> > &grid, int startX, int startY) {
    if (grid[startX][startY] != '1')
      return ;
    else
    {
      grid[startX][startY] = '2';
      if (startY < grid[startX].size() - 1)
        DFS(grid, startX, startY + 1);
      if (startX < grid.size() - 1)
        DFS(grid, startX + 1, startY);
      if (startX > 0)
        DFS(grid, startX - 1, startY);
      if (startY > 0)
        DFS(grid, startX, startY - 1);
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    int num = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[i].size(); ++j)
      {
        if (grid[i][j] == '1')
        {
          DFS(grid, i, j);
          ++num;
        }
      }
    }

    return num;
  }
};

int main()
{
  int x, y;
  scanf("%d%d", &x, &y);

  vector<vector<char> > grid;
  for (int i = 0; i < x; ++i)
  {
    vector<char> row;
    for (int j = 0; j < y; ++j)
    {
      char c = getchar();
      row.push_back(c);
    }
    grid.push_back(row);
    getchar();
  }

  Solution s;
  printf("%d\n", s.numIslands(grid));

  return 0;
}

