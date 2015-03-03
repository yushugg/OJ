#include <iostream>
#include <string>

class Solution {
public:
  std::string intToRoman(int num) {
    int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    std::string romans[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    std::string result = "";
    while (num)
    {
      int i;
      for (i = 0; i < 13; ++i)
      {
        if (num < nums[i])
          break;
      }

      result += romans[i - 1];
      num -= nums[i - 1];
    }

    return result;
  }
};

int main(int argc, char* argv[])
{
  int num;
  std::cin >> num;

  Solution s;
  std::cout << s.intToRoman(num) << std::endl;

  return 0;
}

