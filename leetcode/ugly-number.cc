#include <cstdio>

class Solution {
public:
  bool isUgly(int num) {
    if (!num) return false;
    while (num != 1) {
      if (num % 2 == 0) num /= 2;
      else if (num % 3 == 0) num /= 3;
      else if (num % 5 == 0) num /= 5;
      else return false;
    }
    return true;
  }
};

int main() {
  int num;
  Solution solution;
  while (scanf("%d", &num) != EOF) printf("%d\n", solution.isUgly(num));

  return 0;
}

