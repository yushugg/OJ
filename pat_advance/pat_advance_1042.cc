#include <cstdio>
#include <cstring>


void printCard(const int card, bool last)
{
  char c;
  if (!last)
    c = ' ';
  else
    c = '\n';

  if (card == 52)
    printf("J1%c", c);
  else if (card == 53)
    printf("J2%c", c);
  else
  {
    switch (card / 13)
    {
    case 0:
      putchar('S');
      break;
    case 1:
      putchar('H');
      break;
    case 2:
      putchar('C');
      break;
    case 3:
      putchar('D');
      break;
    }
    printf("%d%c", card % 13 + 1, c);
  }
}

int main()
{
  freopen("in.txt", "r", stdin);

  int K;
  scanf("%d", &K);
  int card[54];
  for (int i = 0; i < 54; ++i)
    card[i] = i;

  int shuffle[54];
  for (int i = 0; i < 54; ++i)
  {
    int temp;
    scanf("%d", &temp);
    shuffle[i] = temp - 1;
  }

  for (int k = 0; k < K; ++k)
  {
    int tmp[54];
    for (int i = 0; i < 54; ++i)
      tmp[shuffle[i]] = card[i];
    for (int i = 0; i < 54; ++i)
      card[i] = tmp[i];
  }

  for (int i = 0; i < 53; ++i)
    printCard(card[i], false);
  printCard(card[53], true);

  return 0;
}

