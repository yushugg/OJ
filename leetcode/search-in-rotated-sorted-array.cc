#include <cstdio>

class Solution {
public:
  int search(int A[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (A[mid] == target)
        return mid;
      // Compare mid and low
      if (A[mid] > A[low])
      {
        if (target > A[mid] || target < A[low])
          low = mid + 1;
        else
          high = mid - 1;
      } else {
        if (target < A[mid] || target > A[high])
          high = mid - 1;
        else
          low = mid + 1;
      }
    }

    return low + 1 < n && A[low + 1] == target ? low + 1 : -1;
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
  printf("%d\n", s.search(A, n, target));

  delete[] A;

  return 0;
}

