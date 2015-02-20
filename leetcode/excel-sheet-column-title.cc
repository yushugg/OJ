#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
  std::string convertToTitle(int n) {
    std::string result;

    --n;
    while (n > 0)
    {
      result.push_back('A' + n % 26);
      n /= 26;
      --n;
    }

    if (!n)
      result.push_back('A');

    std::reverse(result.begin(), result.end());

    return result;
  }
};

int main(int argc, char* argv[])
{
  int n;
  std::cin >> n;

  Solution s;
  std::cout << s.convertToTitle(n) << std::endl;

  return 0;
}

