#include <cstdio>
#include <algorithm>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> result;
    int jump = 1;

    for (int i = digits.size() - 1; i >= 0; --i)
    {
      int num = digits[i] + jump;
      result.push_back(num % 10);
      jump = num / 10;
    }

    if (jump)
      result.push_back(jump);

    // Reverse
    std::reverse(result.begin(), result.end());

    return result;
  }
};
