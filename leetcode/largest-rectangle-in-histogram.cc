#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& height) {
    int maxArea = 0;
    height.push_back(0);
    stack<int> heightStack, indexStack;
    for (int i = 0; i < height.size(); ++i) {
      if (heightStack.empty() || heightStack.top() <= height[i]) {
        heightStack.push(height[i]);
        indexStack.push(i);
      } else {
        int j;
        while (!heightStack.empty() && heightStack.top() >= height[i]) {
          j = indexStack.top(); indexStack.pop();
          int h = heightStack.top(); heightStack.pop();
          maxArea = max(maxArea, (i - j) * h);
        }
        heightStack.push(height[i]);
        indexStack.push(j);
      }
    }

    return maxArea;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> height;
  for (int i = 0; i < size; ++i) {
    int val;
    scanf("%d", &val);
    height.push_back(val);
  }

  Solution solution;
  printf("%d\n", solution.largestRectangleArea(height));

  return 0;
}

