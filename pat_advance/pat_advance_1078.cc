#include <cstdio>

int findPrime(const int num)
{
  for (int i = num; ; ++i)
  {
    if (i == 1)
      continue;
    bool flag = true;
    for (int j = 2; j * j <= i; ++j)
    {
      if (i % j == 0)
      {
        flag = false;
        break;
      }
    }
    if (flag)
      return i;
  }
}

void put2Table(int* table, int tableSize, int num)
{
  int quad, index;

  // (tableSize + quad)^2 % tableSize == quad^2 % tableSize
  for (quad = 0; quad < tableSize; ++quad)
  {
    index = (num + quad*quad) % tableSize;
    if (table[index] == -1)
    {
      table[index] = num;
      printf("%d", index);
      return ;
    }
  }

  printf("-");
}

int main()
{
  // Read data
  int mSize, N;
  scanf("%d%d", &mSize, &N);

  int* num = new int[N];
  for (int i = 0; i < N; ++i)
    scanf("%d", &num[i]);

  // Has table
  int tableSize = findPrime(mSize);
  int* table = new int[tableSize];
  for (int i = 0; i < tableSize; ++i)
    table[i] = -1;

  for (int i = 0; i < N-1; ++i)
  {
    put2Table(table, tableSize, num[i]);
    putchar(' ');
  }
  put2Table(table, tableSize, num[N-1]);
  putchar('\n');

  delete[] num;
  delete[] table;
  return 0;
}

