#include <cstdio>
#include <algorithm>

int countSim(int set1[], int set2[], int size1, int size2)
{
  int sim = 0;
  int p1 = 0, p2 = 0;
  while (p1 != size1 && p2 != size2)
  {
    if (set1[p1] > set2[p2])
      ++p2;
    else if (set1[p1] < set2[p2])
      ++p1;
    else
    {
      ++sim;
      ++p1;
      ++p2;
    }
  }

  return sim;
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);
  int sets[50][10000];
  int size[50];

  for (int i = 0; i < N; ++i)
  {
    int M;
    scanf("%d", &M);
    int idx = 0;
    for (int j = 0; j < M; ++j)
    {
      int temp;
      scanf("%d", &temp);
      if (std::find(sets[i], sets[i]+idx, temp) == sets[i]+idx)
        sets[i][idx++] = temp;
    }
    std::sort(sets[i], sets[i]+idx);
    size[i] = idx;
  }

  int K;
  scanf("%d", &K);
  for (int i = 0; i < K; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    int nc = countSim(sets[a-1], sets[b-1], size[a-1], size[b-1]);
    int nt = size[a-1] + size[b-1] - nc;
    printf("%.1lf%%\n", 1.0*nc/nt*100);
  }

  return 0;
}

