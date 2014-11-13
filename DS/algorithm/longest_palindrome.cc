#include <cstdio>
#include <cstring>
#include <algorithm>

int longestPalindrome(const char* str)
{
  int p[100], mx = 0, id = 0;
  memset(p, 0, sizeof(p));

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

  // Find max
  int max = 0;
  for (int i = 0; str[i] != '\0'; ++i)
    if (max < p[i])
      max = p[i];

  return max - 1;
}

int main()
{
  char str[100];
  char s[100];
  scanf("%s", str);

  s[0] = 'S';
  int count = 1;
  for (int i = 0; str[i] != '\0'; ++i)
  {
    s[count++] = '#';
    s[count++] = str[i];
  }
  s[count++] = '#';
  s[count++] = '\0';
  printf("Longest palindrome: %d\n", longestPalindrome(s));

  return 0;
}

