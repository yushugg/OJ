#include <cstdio>

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    long long a, b, c, temp;
    scanf("%lld%lld%lld", &a, &b, &c);
    bool flag = true;

    printf("Case #%d: ", i+1);
    if (a > 0 && b > 0 && a + b < 0)
      flag = true;
    else if (a < 0 && b < 0 && a + b >= 0)
      flag = false;
    else
      flag = a + b > c;

    if (flag)
      printf("true\n");
    else
      printf("false\n");
  }

  return 0;
}

