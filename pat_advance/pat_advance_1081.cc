#include <cstdio>
#include <algorithm>

struct Rational
{
  long num;
  long deno;
};

Rational rat[105];

Rational add(const Rational& rat1, const Rational& rat2)
{
  Rational rat;
  rat.deno = rat1.deno * rat2.deno;
  rat.num = rat1.num * rat2.deno + rat2.num * rat1.deno;

  return rat;
}

long gcd(long a, long b)
{
  return b ? gcd(b, a % b) : a;
}

void reduce(Rational& rat)
{
  if (rat.num == 0)
  {
    printf("0\n");
    return ;
  }

  if (rat.num < 0)
  {
    printf("-");
    rat.num = -rat.num;
  }

  long factor = rat.num > rat.deno ? gcd(rat.num, rat.deno) : gcd(rat.deno, rat.num);
  rat.num /= factor;
  rat.deno /= factor;

  if (rat.num % rat.deno == 0)
  {
    printf("%ld\n", rat.num / rat.deno);
    return ;
  }

  if (rat.num > rat.deno)
  {
    printf("%ld ", rat.num / rat.deno);
    rat.num -= rat.num / rat.deno * rat.deno;
  }

  printf("%ld/%ld\n", rat.num, rat.deno);
}

void read(int N)
{
  for (int i = 0; i < N; ++i)
  {
    char temp[100];
    scanf("%s", temp);
    sscanf(temp, "%ld/%ld", &rat[i].num, &rat[i].deno);
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  read(N);

  Rational sum;
  sum.num = rat[0].num;
  sum.deno = rat[0].deno;
  for (int i = 1; i < N; ++i)
  {
    sum = add(sum, rat[i]);
  }

  reduce(sum);

  return 0;
}

