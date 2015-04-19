#include <cstdio>

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    unsigned int result = 0, i;
    for (i = 1; i <= n; i <<= 1)
      if (n - m + 1 <= i) result |= m & n & i;

    return result;
  }
};

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  Solution solution;
  printf("%d\n", solution.rangeBitwiseAnd(m, n));

  return 0;
}

