#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  void combinate(std::vector<std::string>& combinations, std::string one, int count, const std::string& digits, const std::string phone[])
  {
    if (count == digits.length())
      combinations.push_back(one);
    else
    {
      std::string all = phone[digits[count] - '0'];
      for (int i = 0; i < all.length(); ++i)
      {
        one.push_back(all[i]);
        combinate(combinations, one, count + 1, digits, phone);
        one.pop_back();
      }
    }
  }

  std::vector<std::string> letterCombinations(std::string digits) {
    const std::string phone[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> result;
    if (digits.empty())
      return result;

    std::string one;
    combinate(result, one, 0, digits, phone);

    return result;
  }
};

int main(int argc, char* argv[])
{
  std::string digits;
  std::cin >> digits;

  Solution s;
  std::vector<std::string> combinations = s.letterCombinations(digits);

  for (auto iter = combinations.begin(); iter != combinations.end(); ++iter)
    std::cout << *iter << " ";
  std::cout << std::endl;

  return 0;
}

