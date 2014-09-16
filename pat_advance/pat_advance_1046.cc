#include <cstdio>
#include <algorithm>


int main()
{
  freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);
  int* dist = new int[N];
  int sum = 0;
  for (int i = 0; i < N; ++i)
  {
    int d;
    scanf("%d", &d);
    dist[i] = sum;
    sum += d;
  }

  int M;
  scanf("%d", &M);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);

    if (a > b)
      std::swap(a, b);

    // Clock-wise
    int clockDist = dist[b-1] - dist[a-1];
    int antiClockDist = sum - clockDist;

    printf("%d\n", std::min(clockDist, antiClockDist));
  }

  delete[] dist;

  return 0;
}

