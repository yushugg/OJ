#include <cstdio>
#include <cstring>

const char icmap[] = {'C', 'J', 'B'};
void addChar(char x, int px[])
{
  switch (x)
  {
  case 'C':
    ++px[0];
    break;
  case 'J':
    ++px[1];
    break;
  case 'B':
    ++px[2];
    break;
  }
}

int compare(char x, char y)
{
  if (x == y)
    return 0;
  else if ((x == 'C' && y == 'J')
    || (x == 'J' && y == 'B')
    || (x == 'B' && y == 'C'))
    return 1;
  else
    return -1;
}

void printTimes(int px[])
{
  for (int i = 0; i < 2; ++i)
    printf("%d ", px[i]);
  printf("%d\n", px[2]);
}

int max(int px[])
{
  int m = 2;
  for (int i = 0; i < 3; ++i)
  {
    if (px[m] < px[i])
      m = i;
  }
  return m;
}

int main()
{
  int N;
  scanf("%d", &N);

  int pa[3], pb[3];
  int wina[3], winb[3];
  memset(wina, 0, 3*sizeof(int));
  memset(winb, 0, 3*sizeof(int));
  memset(pa, 0, 3*sizeof(int));
  memset(pb, 0, 3*sizeof(int));

  getchar();
  for (int i = 0; i < N; ++i)
  {
    char a = getchar();
    getchar();
    char b = getchar();
    getchar();
    int cp = compare(a, b);
    switch (cp)
    {
    case 1:
      addChar(a, pa);
      ++wina[0];
      ++winb[2];
      break;
    case -1:
      addChar(b, pb);
      ++wina[2];
      ++winb[0];
      break;
    case 0:
      ++wina[1];
      ++winb[1];
      break;
    }
  }

  printTimes(wina);
  printTimes(winb);

  printf("%c %c\n", icmap[max(pa)], icmap[max(pb)]);

  return 0;
}

