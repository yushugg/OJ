#include <cstdio>
#include <cstring>
#include <algorithm>

int longestSymmetricString(char str[])
{
  int* p = new int[strlen(str)];
  int mx = 0, id = 0;
  memset(p, 0, strlen(str) * sizeof(p));

  for (int i = 1; str[i] != '\0'; ++i)
  {
    p[i] = mx > i ? std::min(p[2 * id - i], mx - i) : 1;
    while (str[i + p[i]] == str[i - p[i]])
      ++p[i];
    if (i + p[i] > mx)
    {
      mx = i + p[i];
      id = i;
    }
  }

  int max = 0;
  for (int i = 0; str[i] != '\0'; ++i)
  {
    if (max < p[i])
      max = p[i];
  }

  return max;
}

int main()
{
  char str[1001];
  gets(str);
  
  char queryString[3001];

  queryString[0] = '$';
  int i;
  for (i = 0; str[i] != '\0'; ++i)
  {
    queryString[2*i + 1] = '#';
    queryString[2*i + 2] = str[i];
  }
  queryString[2*i + 1] = '#';
  queryString[2*i + 2] = '\0';

  printf("%d\n", longestSymmetricString(queryString) - 1);

  return 0;
}

