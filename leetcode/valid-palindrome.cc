#include <string>
#include <iostream>

class Solution {
public:
  bool isPalindrome(std::string s) {
    if (!s.length())
      return true;

    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
      while (start != s.length() && !((s[start] <= 'z' && s[start] >= 'a') || (s[start] <= 'Z' && s[start] >= 'A') || (s[start] <= '9' && s[start] >= '0')))
        ++start;
      while (end != -1 && !((s[end] <= 'z' && s[end] >= 'a') || (s[end] <= 'Z' && s[end] >= 'A') || (s[end] <= '9' && s[end] >= '0')))
        --end;

      if (start < s.length() && end >= 0 && start < end)
      {
        char a = s[start] <= 'Z' && s[start] >= 'A' ? s[start] + 'a' - 'A' : s[start];
        char b = s[end] <= 'Z' && s[end] >= 'A' ? s[end] + 'a' - 'A' : s[end];
        if (a != b)
          return false;
        else
        {
          ++start;
          --end;
        }
      }
    }

    return true;
  }
};

int main(int argc, char* argv[])
{
  std::string str;
  std::cin >> str;

  Solution s;
  std::cout << s.isPalindrome(str) << std::endl;

  return 0;
}

