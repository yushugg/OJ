#include <cstdio>
#include <cstring>
#include <algorithm>

int* getDigit(int num)
{
  int* digits = new int[4];
  memset(digits, 0, 4*sizeof(int));
  int i = 0;
  while(num)
  {
    digits[i++] = num % 10;
    num /= 10;
  }

  return digits;
}

int getNum(int* digits)
{
  int num = 0;
  for (int i = 0; i < 4; ++i)
  {
    num = num*10 + digits[i];
  }

  return num;
}

void print(int* digits)
{
  for (int i = 0; i < 4; ++i)
  {
    printf("%d", digits[i]);
  }
}

void printReverse(int* digits)
{
  for (int i = 3; i >= 0; --i)
  {
    printf("%d", digits[i]);
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  int diff = N;

  do {
    int* digits = getDigit(diff);
    int* bigs = new int[4];
    int* smalls = new int[4];
    memcpy(bigs, digits, 4*sizeof(int));
    memcpy(smalls, digits, 4*sizeof(int));

    std::sort(smalls, smalls+4);
    std::sort(bigs, bigs+4, [](int x, int y)->bool{return x > y;});

    int big = getNum(bigs);
    int small = getNum(smalls);
    diff = big - small;
    if (diff)
    {
      print(bigs);
      printf(" - ");
      print(smalls);
      printf(" = ");
      printReverse(getDigit(diff));
      putchar('\n');
    }
    delete[] bigs;
    delete[] smalls;
    delete[] digits;
    if (diff == 6174)
      break;
  }while(diff);

  if (!diff)
    printf("%d - %d = 0000\n", N, N);

  return 0;
}

