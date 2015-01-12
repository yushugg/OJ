#include <cstdio>

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (!n)
      return 0;

    int start = 1;
    int num = A[0];

    for (int i = 1; i < n; ++i)
    {
      if (A[i] != num)
      {
        A[start++] = A[i];
        num = A[i];
      }
    }

    return start;
  }
};

int main(int argc, char* argv[])
{
  int A[] = {1, 1, 1, 1, 2, 2, 3, 4, 5, 5};
  int n = 10;

  Solution s;
  int length = s.removeDuplicates(A, n);
  printf("length: %d\n", length);
  for (int i = 0; i < length; ++i)
    printf("%d ", A[i]);

  return 0;
}

