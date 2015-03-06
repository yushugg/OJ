#include <cstdio>

class Solution {
public:
  int uniquePaths(int m, int n) {
    int** paths = new int*[m];
    for (int i = 0; i < m; ++i)
      paths[i] = new int[n];

    paths[0][0] = 1;
    for (int i = 1; i < m; ++i)
      paths[i][0] = 1;
    for (int i = 1; i < n; ++i)
      paths[0][i] = 1;
    for (int i = 1; i < m; ++i)
    {
      for (int j = 1; j < n; ++j)
      {
        paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
      }
    }

    int result = paths[m-1][n-1];

    for (int i = 0; i < m; ++i)
      delete[] paths[i];
    delete[] paths;

    return result;
  }
};

int main(int argc, char* argv[])
{
  int m, n;
  scanf("%d%d", &m, &n);

  Solution s;
  printf("%d\n", s.uniquePaths(m, n));

  return 0;
}

