#include <cstdio>
#include <cstring>

class Solution {
public:
  int strStr(char *haystack, char *needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    if (!needleLen)
      return 0;

    for (int i = 0; haystack[i] != '\0'; ++i)
    {
      if (haystackLen - i < needleLen)
        break;
      int j;
      for (j = 0; needle[j] != '\0'; ++j)
      {
        if (needle[j] != haystack[i + j])
          break;
      }
      if (needle[j] == '\0')
        return i;
    }

    return -1;
  }
};

int main(int argc, char* argv[])
{
  Solution s;

  char haystack[100], needle[100];
  scanf("%s%s", haystack, needle);

  printf("%d\n", s.strStr(haystack, needle));

  return 0;
}

