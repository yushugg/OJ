#include <cstdio>
#include <cmath>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    int dp[n + 1];
    for (int i = 1; i <= n; ++i) {
      int sqrt_num = int(sqrt(i));
      if (sqrt_num * sqrt_num == i) dp[i] = 1;
      else {
        int min = i;
        for (int j = 1; j * j < i; ++j) {
          int p = j * j;
          if (dp[p] + dp[i - p] < min) min = dp[p] + dp[i - p];
        }
        dp[i] = min;
      }
    }
    return dp[n];
  }
};

int main() {
  int n;
  scanf("%d", &n);
  Solution solution;
  printf("%d\n", solution.numSquares(n));

  return 0;
}

