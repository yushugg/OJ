#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int atoi(string str) {
    int start = 0;
    bool positive = true;

    // Strip white spaces
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\r')
      ++start;

    // + or -, use else to avoid +-2
    if (str[start] == '+')
      ++start;
    else if (str[start] == '-')
    {
      positive = false;
      ++start;
    }

    int num = 0;
    while (str[start] <= '9' && str[start] >= '0')
    {
      if (num > INT_MAX / 10)
      {
        if (positive)
          return INT_MAX;
        else
          return INT_MIN;
      }
      num = num * 10 + (str[start++] - '0');
      if (num < 0)
      {
        if (positive)
          return INT_MAX;
        else
          return INT_MIN;
      }
    }
      
    if (str[start] == 'e' || str[start] == 'E')
    {
      int exp = atoi(str.substr(start + 1));
      if (exp >= 0)
      {
        int temp = num;
        while (exp--)
        {
          if (num == 0)
            return num;
          if (num > INT_MAX / 10)
          {
            if (positive)
              return temp;
            else
              return -temp;
          }
          num *= 10;
        }
      }
    }

    if (positive)
      return num;
    else
      return -num;
  }
};

int main()
{
  string str;
  cin >> str;
  Solution s;
  cout << s.atoi(str) << endl;

  return 0;
}

