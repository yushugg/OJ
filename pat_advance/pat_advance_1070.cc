#include <cstdio>
#include <algorithm>

struct MoonCake
{
  double amount;
  double price;
  double per;
};

MoonCake cakes[1000];

bool cmp(MoonCake c1, MoonCake c2)
{
  return c1.per > c2.per;
}

int main()
{
  int N, demand;
  scanf("%d%d", &N, &demand);

  for (int i = 0; i < N; ++i)
    scanf("%lf", &cakes[i].amount);
  for (int i = 0; i < N; ++i)
    scanf("%lf", &cakes[i].price);
  for (int i = 0; i < N; ++i)
    cakes[i].per = cakes[i].price / cakes[i].amount;

  std::sort(cakes, cakes+N, cmp);

  double am = 0;
  double sum = 0;
  for (int i = 0; i < N; ++i)
  {
    if (cakes[i].amount < demand - am)
    {
      sum += cakes[i].price;
      am += cakes[i].amount;
    }
    else
    {
      sum += cakes[i].price * (demand-am) / cakes[i].amount;
      break;
    }
  }

  printf("%.2lf\n", sum);

  return 0;
}

