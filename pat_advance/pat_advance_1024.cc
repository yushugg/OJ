#include <cstdio>
#include <cstring>
#include <algorithm>

bool isPalindromic(int num)
{
  char str[100];
  sprintf(str, "%d", num);
  int length = strlen(str);

  int i = 0, j = length - 1;
  while (i < j)
  {
    if (str[i] != str[j])
      return false;
    ++i;
    --j;
  }

  return true;
}

int reverse(int num)
{
  char str[100];
  sprintf(str, "%d", num);
  std::reverse(str, str + strlen(str));

  int r;
  sscanf(str, "%d", &r);

  return r;
}

int main()
{
  int N, K;
  scanf("%d%d", &N, &K);

  int i = 0;
  bool flag = false;
  while (i < K)
  {
    if (isPalindromic(N))
    {
      printf("%d\n%d\n", N, i);
      flag = true;
      break;
    }
    else
    {
      N = N + reverse(N);
      ++i;
    }
  }

  if (!flag)
  {
    printf("%d\n%d\n", N, K);
  }

  return 0;
}

