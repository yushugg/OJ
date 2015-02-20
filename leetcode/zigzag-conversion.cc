#include <string>
#include <iostream>

class Solution {
public:
  std::string convert(std::string s, int nRows) {
    std::string result;

    if (nRows == 1)
      result = s;

    if (s.length() && nRows > 1)
    {
      size_t times = (s.length() - 1) / ((nRows - 1) * 2);
      size_t lastPos = (s.length() - 1) % ((nRows - 1) * 2);

      for (int i = 0; i < nRows; ++i)
      {
        if (i == 0 || i == nRows - 1)
        {
          // No elements in the center
          size_t lastTimes = times + 1;
          if (i)
            lastTimes = lastPos < nRows - 1 ? times : times + 1;

          for (size_t j = 0; j < lastTimes; ++j)
          {
            result.push_back(s[i + (nRows - 1) * 2 * j]);
          }
        }
        else
        {
          // One element in the center
          size_t lastTimes = lastPos < i ? times : times + 1;
          for (size_t j = 0; j < lastTimes; ++j)
          {
            result.push_back(s[i + (nRows - 1) * 2 * j]);
            if (j != lastTimes - 1 || lastPos < i || lastPos >= (nRows - 1) * 2 - i)
              result.push_back(s[2 * (nRows - 1) - i + (nRows - 1) * 2 * j]);
          }
        }
      }
    }

    return result;
  }
};

int main(int argc, char* argv[])
{
  std::string str;
  int rows;
  std::cin >> str >> rows;

  Solution s;
  std::cout << "Converted: " << s.convert(str, rows) << std::endl;

  return 0;
}

