#include <cstdio>
#include <climits>

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (!divisor) return INT_MAX;
    if (!dividend) return 0;
    bool flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
    long div = dividend, d = divisor;
    if (div < 0) div = -div;
    if (d < 0) d = -d;
    if (div < d) return 0;
    if (div == d) return flag ? 1 : -1;
    if (d == 1) {
      if (dividend == INT_MIN && divisor == -1) return INT_MAX; else return flag ? div : -div;
    }
    long di = d;
    int count = 0;
    while (di << 1 < div) {
      di <<= 1;
      ++count;
    }
    count = 1 << count;
    count += divide(div - di, d);

    return flag ? count : -count;
  }
};

int main() {
  int dividend, divisor;
  scanf("%d%d", &dividend, &divisor);

  Solution solution;
  printf("%d\n", solution.divide(dividend, divisor));

  return 0;
}

