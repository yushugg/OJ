#include <cstdio>
#include <string>

class Solution {
public:
  int charToInt(char c)
  {
    if (c <= 'Z' && c >= 'A')
      c += 'a' - 'A';

    int num = 0;
    switch(c)
    {
    case 'i':
      num = 1;
      break;
    case 'v':
      num = 5;
      break;
    case 'x':
      num = 10;
      break;
    case 'l':
      num = 50;
      break;
    case 'c':
      num = 100;
      break;
    case 'd':
      num = 500;
      break;
    case 'm':
      num = 1000;
      break;
    }

    return num;
  }

  int romanToInt(std::string s) {
    int sum = 0;
    for (size_t i = 0; i != s.length() - 1; ++i)
    {
      if (charToInt(s[i]) < charToInt(s[i+1]))
        sum -= charToInt(s[i]);
      else
        sum += charToInt(s[i]);
    }
    sum += charToInt(s[s.length() - 1]);

    return sum;
  }
};

int main(int argc, char* argv[])
{
  Solution solution;
  printf("%d\n", solution.romanToInt("LXIX"));

  return 0;
}

