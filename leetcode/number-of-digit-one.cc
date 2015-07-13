#include <cstdio>

using namespace std;

class Solution {
public:
  int countDigitOne(int n) {
    // 231: (100 + )
    if (n <= 0) return 0;
    long nl = n;
    long count = 0;
    long fact = 1;
    while (fact <= nl) {
      long former = nl / (fact * 10);
      long latter = nl % fact;
      long num = nl % (fact * 10) / fact;
      if (num > 1) count += (former + 1) * fact;
      else count += former * fact + (num ? latter + 1 : 0);
      fact *= 10;
    }
    return count;
  }
};

int main() {
  int n;
  Solution solution;

  while (scanf("%d", &n) != EOF) printf("%d\n", solution.countDigitOne(n));

  return 0;
}

