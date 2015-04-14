#include <cstdio>
#include <algorithm>

class Solution {
public:
  int trap(int A[], int n) {
    int sum = 0;
    int down = 0, up = 0;
    while (down < n && up < n) {
      while (down < n && A[down] <= A[down + 1]) ++down;
      up = down + 1;
      while (up < n && A[up] < A[down]) ++up;
      if (up == n && A[up - 1] < A[down]) {
        std::reverse(A + down, A + n);
        sum += trap(A + down, n - down);
      } else {
        int min = A[up] < A[down] ? A[up] : A[down];
        for (int i = down + 1; i < up; ++i) if (min - A[i] > 0) sum += min - A[i];
      }
      down = up;
    }

    return sum;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  int *A = new int[n];
  for (int i = 0; i < n; ++i) scanf("%d", &A[i]);

  Solution s;
  printf("%d\n", s.trap(A, n));

  delete[] A;
  
  return 0;
}

