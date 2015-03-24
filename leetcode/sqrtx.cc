#include <cstdio>

class Solution {
public:
  int sqrt(int x) {
    const int maxSqrt = 46340;
    const int maxNum = 2147395600;

    if (x >= maxNum)
      return maxSqrt;

    int start = 0;
    int end = maxSqrt;
    int mid;
    while (start <= end)
    {
      mid = (start + end) / 2;
      if (mid * mid < x)
        start = mid + 1;
      else if (mid * mid > x)
        end = mid - 1;
      else
        return mid;
    }

    return end;
  }
};

int main(int argc, char* argv[])
{
  Solution s;
  while (true)
  {
    int x;
    scanf("%d", &x);
    printf("%d\n", s.sqrt(x));
  }

  return 0;
}

