#include <cstdio>

class Solution {
public:
  int maxSubArray(int A[], int n) {
    int maxSum = A[0];
    int thisSum = 0;
    for (int i = 0; i < n; ++i)
    {
      thisSum += A[i];
      if (thisSum > maxSum)
        maxSum = thisSum;
      if (thisSum < 0)
        thisSum = 0;
    }

    return maxSum;
  }
};

int main(int argc, char* argv[])
{
  int A[] = {-3, -2, 0, -1};
  int n = 4;

  Solution s;
  printf("%d\n", s.maxSubArray(A, n));

  return 0;
}

