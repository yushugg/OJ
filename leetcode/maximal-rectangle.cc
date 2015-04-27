#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.empty()) return 0;
    int left = matrix[0].size() - 1, right = 0, up = matrix.size() - 1, down = 0;
    if (left == right && right == up && up == down && down == 0 && matrix[0][0] == '0') return 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == '1') {
          if (j < left) left = j;
          if (j > right) right = j;
          if (i < up) up = i;
          if (i > down) down = i;
        }
      }
    }

    if (left > right || up > down) return 0;

    return (right - left + 1) * (down - up + 1);
  }
};

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  vector<vector<char> > matrix;
  getchar();
  for (int i = 0; i < m; ++i) {
    vector<char> line;
    for (int j = 0; j < n; ++j) {
      char c = getchar();
      line.push_back(c);
    }
    matrix.push_back(line);
    getchar();
  }

  Solution s;
  printf("%d\n", s.maximalRectangle(matrix));

  return 0;
}

