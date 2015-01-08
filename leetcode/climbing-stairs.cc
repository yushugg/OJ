#include <cstdio>
#include <cstring>

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;

    int way1 = 1;
    int way2 = 2;
    int way;
    for (int i = 3; i <= n; ++i)
    {
      way = way1 + way2;
      way1 = way2;
      way2 = way;
    }

    return way;
  }
};

int main(int argc, char* argv[])
{
  Solution solution;
  printf("%d\n", solution.climbStairs(44));

  return 0;
}

