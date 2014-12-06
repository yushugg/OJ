#include <cstdio>
#include <algorithm>

class Solution {
public:
  int removeDuplicates(int A[], int n)
  {
    // Sort firstly
    std::sort(A, A + n);

  }
};


int main(int argc, char* argv[])
{
  // Read n and array
  int n;
  scanf("%d", &n);
  int* A = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);

  // Resolve this problem
  Solution solution;
  int length = solution.removeDuplicates(A, n);

  // Output results
  printf("Length: %d\n", length);
  for (int i = 0; i < length - 1; ++i)
    printf("%d ", A[i]);
  printf("%d\n", A[length - 1]);

  // Free memory
  delete[] A;

  return 0;
}

