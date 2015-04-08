#include <cstdio>
#include <algorithm>

class Solution {
public:
  // Find kth
  double find(int A[], int m, int B[], int n, int k) {
    if (m > n)
      return find(B, n, A, m, k);
    
    if (!m)
      return B[k - 1];

    if (k == 1)
      return A[0] < B[0] ? A[0] : B[0];

    int a = std::min(k / 2, m);
    int b = k - a;

    if (A[a - 1] == B[b - 1])
      return A[a - 1];
    else if (A[a - 1] < B[b - 1])
      return find(A + a, m - a, B, n, k - a);
    else
      return find(A, m, B + b, n - b, k - b);
  }

  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2)
      return find(A, m, B, n, (m + n) / 2 + 1);
    else
      return (find(A, m, B, n, (m + n) / 2) + find(A, m, B, n, (m + n) / 2 + 1)) / 2;
  }
};

int main()
{
  int m, n;
  scanf("%d", &m);
  int *A = new int[m];
  for (int i = 0; i < m; ++i)
    scanf("%d", &A[i]);

  scanf("%d", &n);
  int *B = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &B[i]);

  Solution s;
  printf("%lf\n", s.findMedianSortedArrays(A, m, B, n));

  return 0;
}

