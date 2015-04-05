#include <cstdio>
#include <algorithm>
#include <climits>

class Solution {
public:
  int maxProduct(int A[], int n) {
    int front, end;
    front = end = 1;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
      front *= A[i];
      end *= A[n - i - 1];
      max = std::max(max, std::max(front, end));
      if (!front)
        front = 1;
      if (!end)
        end = 1;
    }

    return max;
  }
};

int main()
{
  int size;
  scanf("%d", &size);
  int *A = new int[size];
  for (int i = 0; i < size; ++i)
    scanf("%d", &A[i]);

  Solution s;
  printf("%d\n", s.maxProduct(A, size));

  delete[] A;

  return 0;
}

