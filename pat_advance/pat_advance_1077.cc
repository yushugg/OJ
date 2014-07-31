#include <cstdio>
#include <cstring>

int main()
{
  freopen("in.txt", "r", stdin);
  // Read data
  int N;
  scanf("%d", &N);
  char sentence[100][260];

  char empty[2];
  gets(empty);
  for (int i = 0; i < N; ++i)
    gets(sentence[i]);

  int index = 0;
  while (true)
  {
    bool same = true;
    if (!strlen(sentence[0]))
    {
      same = false;
      break;
    }
    if (index >= strlen(sentence[0]))
      break;
    char c = sentence[0][strlen(sentence[0]) - index - 1];
    for (int i = 1; i < N; ++i)
    {
      int len = strlen(sentence[i]);
      if (!len)
      {
        same = false;
        break;
      }
      if (index >= len)
        break;
      if (sentence[i][len-index-1] != c)
      {
        same = false;
        break;
      }
    }
    if (same)
      ++index;
    else
      break;
  }

  if (index)
  {
    for (int i = strlen(sentence[0]) - index; i < strlen(sentence[0]); ++i)
      putchar(sentence[0][i]);
    putchar('\n');
  }
  else
    puts("nai");

  return 0;
}

