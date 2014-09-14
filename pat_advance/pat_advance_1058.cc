#include <cstdio>

int main()
{
  int A[3];
  int B[3];
  int C[3];
  int carry[3];
  scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
  scanf("%d.%d.%d", &B[0], &B[1], &B[2]);

  C[2] = A[2] + B[2];
  if (C[2] >= 29)
  {
    carry[1] = 1;
    C[2] -= 29;
  }
  else
    carry[1] = 0;

  C[1] = A[1] + B[1] + carry[1];
  if (C[1] >= 17)
  {
    carry[0] = 1;
    C[1] -= 17;
  }
  else
    carry[0] = 0;

  C[0] = A[0] + B[0] + carry[0];

  printf("%d.%d.%d\n", C[0], C[1], C[2]);

  return 0;
}

