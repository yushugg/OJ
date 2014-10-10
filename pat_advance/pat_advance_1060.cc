#include <cstdio>
#include <cstring>

double format(double d, int& exp)
{
  if (d >= 1)
  {
    int num = static_cast<int>(d);
    double sci = d;
    while (num)
    {
      ++exp;
      num /= 10;
      sci /= 10;
    }

    return sci;
  }
  else if (d == 0)
  {
    return 0;
  }
  else
  {
    double sci = d;
    while (sci < 1)
    {
      --exp;
      sci *= 10;
    }
    ++exp;
    sci /= 10;
    return sci;
  }
}

bool equal(double d1, double d2, int exp1, int exp2, int N)
{
  double f1 = d1;
  double f2 = d2;
  int count = 0;
  while (count != N)
  {
    f1 *= 10;
    f2 *= 10;
    ++count;
  }
  if (exp1 == exp2 && static_cast<int>(f1) == static_cast<int>(f2))
    return true;
  else
    return false;
}

void chop(double d, int N)
{
  if (d != 0)
  {
    char* result = new char[N+3];
    sprintf(result, "%lf", d);
    for (int i = 0; i < N+2; ++i)
    {
      if (i < strlen(result))
        putchar(result[i]);
      else
        putchar('0');
    }
  }
  else
  {
    printf("0.");
    for (int i = 0; i < N; ++i)
      putchar('0');
  }
}

int main()
{
  int N;
  double A, B;
  scanf("%d%lf%lf", &N, &A, &B);

  int expA = 0;
  int expB = 0;
  double fa = format(A, expA);
  double fb = format(B, expB);
  bool eq = equal(fa, fb, expA, expB, N);

  if (eq)
  {
    printf("YES ");
    chop(fa, N);
    printf("*10^%d\n", expA);
  }
  else
  {
    printf("NO ");
    chop(fa, N);
    printf("*10^%d ", expA);
    chop(fb, N);
    printf("*10^%d\n", expB);
  }

  return 0;
}

