#include <cstdio>

long producePrime(long start)
{
  for (long i = start; ; ++i)
  {
    bool isPrime = true;
    for (long j = 2; j * j <= i; ++j)
    {
      if (i % j == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
      return i;
  }
}

int main()
{
  long number;
  scanf("%ld", &number);
  printf("%ld=", number);

  if (number == 1)
    printf("1");

  long start = 2;
  bool first = true;
  while (number != 1)
  {
    long count = 0;
    while (number % start == 0)
    {
      ++count;
      number /= start;
    }
    if (count)
    {
      if (!first)
        putchar('*');
      else
        first = false;
      if (count > 1)
        printf("%ld^%ld", start, count);
      else if (count == 1)
        printf("%ld", start);
    }
    start = producePrime(start + 1);
  }
  putchar('\n');

  return 0;
}

