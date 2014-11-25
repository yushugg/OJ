#include <cstdio>

void lcs(int* x, int* y, int xn, int yn, int** common, int** flag)
{
  for (int i = 0; i < xn; ++i)
    common[i][0] = 0;
  for (int j = 0; j < yn; ++j)
    common[0][j] = 0;

  for (int i = 1; i < xn; ++i)
    for (int j = 1; j < yn; ++j)
    {
      if (x[i] == y[j])
      {
        common[i][j] = common[i-1][j-1] + 1;
        flag[i][j] = 1;
      }
      else if (common[i][j-1] >= common[i-1][j])
      {
        common[i][j] = common[i][j-1];
        flag[i][j] = 2;
      }
      else if (common[i][j-1] < common[i-1][j])
      {
        common[i][j] = common[i-1][j];
        flag[i][j] = 3;
      }
    }
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);

  int M;
  scanf("%d", &M);
  ++M;
  int* x = new int[M];
  for (int i = 1; i < M; ++i)
    scanf("%d", &x[i]);

  int K;
  scanf("%d", &K);
  ++K;
  int* y = new int[K];
  for (int i = 1; i < K; ++i)
    scanf("%d", &y[i]);

  int** common = new int*[M];
  for (int i = 0; i < M; ++i)
    common[i] = new int[K];

  int** flag = new int*[M];
  for (int i = 0; i < M; ++i)
    flag[i] = new int[K];

  lcs(x, y, M, K, common, flag);

  printf("%d\n", common[M-1][K-1]);
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < K - 1; ++j)
    {
      printf("%d ", common[i][j]);
    }
    printf("%d\n", common[i][K-1]);
  }

  return 0;
}

