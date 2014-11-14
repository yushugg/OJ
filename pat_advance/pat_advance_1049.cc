#include <cstdio>
#include <cstring>
#include <algorithm>

int tens(int radix)
{
  int cnt = 0;
  int product = 1;
  while (cnt < radix - 1)
  {
    product *= 10;
    ++cnt;
  }

  return product;
}

int countOnes(int num)
{
  int sum = 0;
  char str[11];
  sprintf(str, "%d", num);
  int length = strlen(str);

  if (length == 1)
    return 1;

  for (int i = length; i >= 1; --i)
  {
    int digit = str[length - i] - '0';
    if (digit > 1)
    {
      int front = num / (tens(i) * 10) - tens(length - i) + 1;
      if (front <= 0)
        front = 1;
      sum += front * tens(i);
    }
    else if (digit == 1)
    {
      int front = num / (tens(i) * 10) - tens(length - i);
      if (front <= 0)
        front = 0;
      sum += front * tens(i);
      int back = num % (tens(i)) + 1;
      sum += back;
    }
    else
    {
      int front = num / (tens(i) * 10) - tens(length - i);
      sum += front * tens(i);
    }
  }

  return sum;
}

int main()
{
  int N;
  scanf("%d", &N);

  int sum = 0;
  char str[11];
  sprintf(str, "%d", N);
  int length = strlen(str);

  sum += countOnes(N);
  for (int i = length; i >= 1; --i)
  {
    sum += countOnes(tens(i) - 1);
  }

  printf("%d\n", sum - 1);

  return 0;
}

