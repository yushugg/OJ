#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  enum Direction { Left, Right, Up, Down };
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    if (!matrix.size()) return result;
    Direction direction = Right;
    int m = matrix.size(), n = matrix[0].size(), level = 1;
    int i = 0, j = 0, total = m * n, count = 0;
    while (count < total - 1) {
      switch (direction) {
      case Left:
        if (j > level - 1) { result.push_back(matrix[i][j]); --j; ++count; }
        else direction = Up;
        break;
      case Right:
        if (j < n - 1) { result.push_back(matrix[i][j]); ++j; ++count; }
        else direction = Down;
        break;
      case Up:
        if (i > level) { result.push_back(matrix[i][j]); --i; ++count; }
        else { direction = Right; ++level; --m; --n; }
        break;
      case Down:
        if (i < m - 1) { result.push_back(matrix[i][j]); ++i; ++count; }
        else direction = Left;
        break;
      }
    }
    result.push_back(matrix[i][j]);
    
    return result;
  }
};

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  vector<vector<int> > matrix;
  for (int i = 0; i < m; ++i) {
    vector<int> line;
    for (int j = 0; j < n; ++j) {
      int val;
      scanf("%d", &val);
      line.push_back(val);
    }
    matrix.push_back(line);
  }

  Solution solution;
  vector<int> result = solution.spiralOrder(matrix);
  for (auto iter = result.begin(); iter != result.end(); ++iter)
    printf("%d,", *iter);
  puts("");

  return 0;
}

