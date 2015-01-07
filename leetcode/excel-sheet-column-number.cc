#include <iostream>
#include <string>


class Solution {
public:
  int titleToNumber(std::string s) {
    int sum = 0;
    for (size_t i = 0; i != s.length(); ++i)
      sum = sum * 26 + (s[i] - 'A' + 1);

    return sum;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;

  int number = solution.titleToNumber("AC");

  std::cout << number << std::endl;

  return 0;
}
