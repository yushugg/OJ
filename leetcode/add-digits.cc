#include <cstdio>

class Solution {
public:
  int addDigits(int num) {
    if (!num) return 0;
    return (num - 1) % 9 + 1;
  }
};

int main() {
  int num;
  Solution solution;
  while (scanf("%d", &num) != EOF) printf("%d\n", solution.addDigits(num));

  return 0;
}

