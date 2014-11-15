#include <cstdio>
#include <algorithm>

int main()
{
  int N, M;
  scanf("%d%d", &N, &M);

  int* coins = new int[N];
  int* temp = new int[N];
  for (int i = 0; i < N; ++i)
    scanf("%d", &coins[i]);

  std::sort(coins, coins + N);
  for (int i = 0; i < N; ++i)
    temp[i] = M - coins[N - i - 1];

  bool solution = false;
  int first = 0;
  int second = 0;
  while (first != N - 1 && second != N - 1)
  {
    if (coins[first] < temp[second])
      ++first;
    else if (coins[first] > temp[second])
      ++second;
    else
    {
      solution = true;
      break;
    }
  }

  // Like M = 14, one of the number is 7
  if (coins[first] * 2 == M)
  {
    int count = std::count(coins, coins+N, coins[first]);
    if (count <= 1)
      solution = false;
  }

  if (!solution)
    printf("No Solution\n");
  else
    printf("%d %d\n", coins[first], M - coins[first]);

  delete[] coins;
  delete[] temp;

  return 0;
}

