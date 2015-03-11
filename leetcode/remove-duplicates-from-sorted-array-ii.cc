#include <cstdio>

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int count = 0;
    int current = A[0];
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
      if (current == A[i])
      {
        ++count;
        if (count <= 2)
          A[idx++] = A[i];
      }
      else
      {
        count = 1;
        A[idx++] = A[i];
        current = A[i];
      }
    }

    return idx;
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
  int result = s.removeDuplicates(A, n);
  
  printf("%d\n", result);
  for (int i = 0; i < result; ++i)
    printf("%d ", A[i]);
  putchar('\n');

  delete[] A;

  return 0;
}

