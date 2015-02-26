#include <cstdio>

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
      mid = (low + high) / 2;
      if (target < A[mid])
        high = mid - 1;
      else if (target > A[mid])
        low = mid + 1;
      else
        return mid;
    }

    if (A[mid] < target)
      return mid + 1;
    else
      return mid;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);

  int* A = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);

  int target;
  scanf("%d", &target);

  Solution s;
  printf("%d\n", s.searchInsert(A, n, target));

  return 0;
}

