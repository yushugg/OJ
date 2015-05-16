#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

class Solution {
public:
  int maxHistogram(vector<int> height) {
    height.push_back(0);
    stack<int> heightStack;
    stack<int> indexStack;
    heightStack.push(height[0]);
    indexStack.push(0);
    int maxArea = 0;
    for (int i = 1; i < height.size(); ++i) {
      if (heightStack.top() <= height[i]) { heightStack.push(height[i]); indexStack.push(i); }
      else {
        int idx;
        while (!heightStack.empty() && heightStack.top() > height[i]) {
          idx = indexStack.top();
          maxArea = max(maxArea, (i - idx) * heightStack.top());
          heightStack.pop(); indexStack.pop();
        }
        heightStack.push(height[i]);
        indexStack.push(idx);
      }
    }
    return maxArea;
  }

  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    vector<vector<int> > height(matrix.size(), vector<int>(matrix[0].size(), 0));
    int maxArea = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == '1') height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
      }
      int area = maxHistogram(height[i]);
      maxArea = max(maxArea, area);
    }
    return maxArea;
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

