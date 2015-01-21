// Or just use reverse, and deal with some overflow cases
#include <cstdio>
#include <cmath>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    int len = 0;
    int num = x;
    while (num)
    {
      num /= 10;
      ++len;
    }

    for (int i = 0; i < len / 2; ++i)
    {
      if (x / int(pow(10, len - i - 1)) % 10 != x % int(pow(10, i + 1)) / (int(pow(10, i))))
        return false;
    }

    return true;
  }
};

int main(int argc, char* argv[])
{
  Solution s;
  
  while (true)
  {
    int x;
    scanf("%d", &x);
    
    if (s.isPalindrome(x))
      printf("true\n");
    else
      printf("false\n");
  }

  return 0;
}

