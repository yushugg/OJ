#include <cstdio>
#include <cstring>

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int p = strlen(s) - 1;
    while (p >= 0 && s[p] == ' ')
      --p;

    int count = 0;
    for (int i = p; i >= 0 && s[i] != ' '; --i)
      ++count;

    return count;
  }
};

int main(int argc, char* argv[])
{
  Solution s;
  printf("%d\n", s.lengthOfLastWord("a "));

  return 0;
}

