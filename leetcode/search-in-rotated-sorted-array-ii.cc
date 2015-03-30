#include <cstdio>

class Solution {
public:
  bool search(int A[], int n, int target) {
    // These are wrong answers
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (A[mid] == target)
        return true;

      if (A[mid] > A[low])
      {
        if (A[mid] < target || target < A[low])
          low = mid + 1;
        else
          high = mid - 1;
      }
      else if (A[mid] < A[low])
      {
        if (A[mid] > target || target > A[high])
          high = mid - 1;
        else
          low = mid + 1;
      } else
        ++low;
    }

    return false;
  }
};

int main(int argc, char* argv[])
{
  int A[] = { 3, 4, 4, 5, 1, 2, 2, 2, 3 };
  int size = 9;

  Solution s;
  for (int i = 0; i < 6; ++i)
    printf("%d\n", s.search(A, size, i));

  return 0;
}

