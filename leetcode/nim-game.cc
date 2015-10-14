#include <cstdio>

using namespace std;

class Solution {
public:
  bool canWinNim(int n) {
    return n % 4;
  }
};

int main() {
  Solution solution;
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", solution.canWinNim(n));
  }

  return 0;
}

