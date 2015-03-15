#include <vector>
#include <cstdio>

class Solution {
public:
  std::vector<int> searchRange(int A[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid;
    int start = -1;
    while (low <= high)
    {
      mid = low + (high - low) / 2;
      if (A[mid] == target)
      {
        if (!mid || A[mid - 1] < target)
        {
          start = mid;
          break;
        }
        else
          high = mid - 1;
      }
      else if (A[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }

    // Find end
    low = 0;
    high = n - 1;
    int end = -1;
    while (low <= high)
    {
      mid = low + (high - low) / 2;
      if (A[mid] == target)
      {
        if (mid == n - 1 || A[mid + 1] > target)
        {
          end = mid;
          break;
        }
        else
          low = mid + 1;
      }
      else if (A[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }

    std::vector<int> result;
    result.push_back(start);
    result.push_back(end);

    return result;
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
  std::vector<int> result = s.searchRange(A, n, target);

  printf("[%d, %d]\n", result[0], result[1]);

  delete[] A;

  return 0;
}

