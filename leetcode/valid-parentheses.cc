#include <string>
#include <iostream>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;

    for (size_t i = 0; i != s.length(); ++i)
    {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        stack.push(s[i]);
      else if (!stack.empty())
      {
        if (s[i] == ')')
        {
          if (stack.top() == '(')
            stack.pop();
          else
            return false;
        } else if (s[i] == '}')
        {
          if (stack.top() == '{')
            stack.pop();
          else
            return false;
        } else
        {
          if (stack.top() == '[')
            stack.pop();
          else
            return false;
        }
      }
      else
        return false;
    }

    if (stack.empty())
      return true;
    else
      return false;
  }
};

int main(int argc, char* argv[])
{
  std::string str;
  std::cin >> str;

  Solution s;
  std::cout << s.isValid(str) << std::endl;

  return 0;
}

