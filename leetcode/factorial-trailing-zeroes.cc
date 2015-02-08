#include <cstdio>

class Solution {
public:
  int trailingZeroes(int n) {
    // Count 5s
    if (n <= 0)
      return 0;
    int trailings = n;

    // Count levels
    int level = 0;
    while (n / 5) {
      ++level;
      n /= 5;
    }

    int zeroes = 0;
    for (int i = 0; i < level; ++i)
    {
      trailings /= 5;
      zeroes += trailings;
    }

    return zeroes;
  }
};

int main(int argc, char* argv[])
{
  Solution s;
  printf("%d\n", s.trailingZeroes(5));

  return 0;
}

