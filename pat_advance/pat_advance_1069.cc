#include <cstdio>
#include <cstring>
#include <algorithm>

bool cmp(char a, char b)
{
  return a > b;
}

void int2Str(int res, char result[])
{
  for (int j = 0; j < 4; ++j)
    result[j] = '0';
  result[4] = '\0';
  int i = 3;
  while (res)
  {
    result[i--] = res % 10 + '0';
    res /= 10;
  }
}

int main()
{
  char result[5];
  char first[5];
  char second[5];
  int res, fir, sec;

  scanf("%d", &res);
  int2Str(res, result);
  bool same = true;
  char digit = result[0];
  for (int i = 1; i < 4; ++i)
  {
    if (result[i] != digit)
    {
      same = false;
      break;
    }
  }
  if (same)
  {
    printf("%s - %s = 0000\n", result, result);
    return 0;
  }

  do
  {
    strcpy(first, result);
    strcpy(second, result);

    // Sort
    std::sort(first, first+4, cmp);
    std::sort(second, second+4);
    sscanf(first, "%d", &fir);
    sscanf(second, "%d", &sec);
    res = fir - sec;
    int2Str(res, result);
    printf("%s - %s = %s\n", first, second, result);
  } while(res != 6174);
  
  return 0;
}

