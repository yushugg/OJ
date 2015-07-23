#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int row = matrix.size() - 1, col = 0;
    while (row >= 0 && col < matrix[0].size()) {
      if (matrix[row][col] > target) --row;
      else if (matrix[row][col] < target) ++col;
      else return true;
    }
    return false;
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  int rows, cols, target;
  scanf("%d%d", &rows, &cols);
  vector<vector<int>> matrix;
  for (int i = 0; i < rows; ++i) {
    vector<int> line;
    for (int j = 0; j < cols; ++j) {
      int val;
      scanf("%d", &val);
      line.push_back(val);
    }
    matrix.push_back(line);
  }

  // Test matrix
  for (auto line : matrix) {
    for (int val : line) {
      printf(" %d", val);
    }
    puts("");
  }

  scanf("%d", &target);

  Solution solution;
  printf("%d\n", solution.searchMatrix(matrix, target));

  return 0;
}

