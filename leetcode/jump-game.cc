#include <cstdio>

class Solution {
public:
  bool canJump(int A[], int n) {
    int start, end;
    start = end = 0;
    while (end < n && start <= end)
    {
      int last = end;
      for (int i = start; i <= end; ++i)
      {
        int temp = A[i] + i;
        if (temp > end && last < temp)
          last = temp;
      }
      start = end + 1;
      end = last;
    }

    if (end < n - 1)
      return false;
    else
      return true;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);

  int* A = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);

  Solution s;
  if (s.canJump(A, n))
    printf("true\n");
  else
    printf("false\n");

  delete[] A;

  return 0;
}

