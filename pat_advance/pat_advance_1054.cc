#include <cstdio>


int main()
{
  freopen("in.txt", "r", stdin);

  int M, N;
  int dominant = -1;
  int count = 0;
  scanf("%d%d", &M, &N);
  for (size_t i = 0; i != N; ++i)
    for (size_t j = 0; j != M; ++j)
    {
      int color;
      scanf("%d", &color);
      if (color != dominant)
      {
        if (count <= 0)
        {
          dominant = color;
          count = 1;
        }
        else
          --count;
      }
      else
        ++count;
    }

  printf("%d\n", dominant);

  return 0;
}

