#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::string say(std::string str)
  {
    std::string read;

    char c = str[0];
    int count = 0;
    int idx = 0;
    while (idx < str.length())
    {
      if (str[idx] == c)
        ++count;
      else
      {
        read.push_back('0' + count);
        read.push_back(c);
        count = 1;
        c = str[idx];
      }

      ++idx;
    }

    read.push_back('0' + count);
    read.push_back(c);

    return read;
  }

  std::string countAndSay(int n) {
    std::string str = "1";
    for (int i = 0; i < n - 1; ++i)
      str = say(str);

    return str;
  }
};

int main(int argc, char* argv[])
{
  Solution s;
  std::cout << s.countAndSay(0) << std::endl;

  return 0;
}

