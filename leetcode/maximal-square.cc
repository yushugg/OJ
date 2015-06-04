#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    // area: max area containing element i, j
    // maximal size of the square that can be achieved at point(i, j)
    // for i > 0 and j > 0, if matrix[i][j] = 0, area[i][j] = 0; if matrix[i][j] = 1, area[i][j] = min(area[i - 1][j], area[i][j - 1], area[i - 1][j - 1]) + 1
    vector<vector<int>> area(matrix.size(), vector<int>(matrix[0].size(), 0));
    int maxArea = 0;
    for (int i = 0; i < matrix.size(); ++i) { area[i][0] = matrix[i][0] - '0'; maxArea = max(maxArea, area[i][0]); }
    for (int j = 0; j < matrix[0].size(); ++j) { area[0][j] = matrix[0][j] - '0'; maxArea = max(maxArea, area[0][j]); }
    for (int i = 1; i < matrix.size(); ++i) {
      for (int j = 1; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == '1') {
          if (area[i - 1][j] && area[i][j - 1]) {
            if (area[i - 1][j] != area[i][j - 1]) area[i][j] = min(area[i - 1][j], area[i][j - 1]) + 1;
            else if (matrix[i - area[i - 1][j]][j - area[i][j - 1]] != '1') area[i][j] = area[i - 1][j];
            else area[i][j] = area[i - 1][j] + 1;
          } else area[i][j] = 1;
        }
        maxArea = max(maxArea, area[i][j]);
      }
    }

    return maxArea * maxArea;
  }
};

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  vector<vector<char>> matrix;
  for (int i = 0; i < m; ++i) {
    vector<char> line;
    getchar();
    for (int j = 0; j < n; ++j) {
      char c = getchar();
      line.push_back(c);
    }
    matrix.push_back(line);
  }

  Solution solution;
  printf("%d\n", solution.maximalSquare(matrix));

  return 0;
}

