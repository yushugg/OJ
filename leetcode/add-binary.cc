#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string result;

    int maxLen = a.length() > b.length() ? a.length() : b.length();

    int carry = 0;
    for (int i = 0; i < maxLen; ++i)
    {
      int anum = 0;
      int bnum = 0;
      if (a.length() > i)
        anum = a[a.length() - i - 1] - '0';
      if (b.length() > i)
        bnum = b[b.length() - i - 1] - '0';
      int sum = anum + bnum + carry;

      if (sum >= 2)
      {
        result.push_back('0' + sum - 2);
        carry = 1;
      } else {
        result.push_back('0' + sum);
        carry = 0;
      }
    }

    if (carry)
      result.push_back('1');

    std::reverse(result.begin(), result.end());

    return result;
  }
};

int main(int argc, char* argv[])
{
  std::string a, b;
  std::cin >> a >> b;

  Solution s;
  std::cout << s.addBinary(a, b) << std::endl;

  return 0;
}

