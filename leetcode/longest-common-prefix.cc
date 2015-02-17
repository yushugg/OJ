#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    std::string commonPrefix;

    if (strs.empty())
      return commonPrefix;

    size_t minLen = strs[0].length();
    for (auto iter = strs.begin(); iter != strs.end(); ++iter)
    {
      if (iter->length() < minLen)
        minLen = iter->length();
    }

    size_t len;
    for (len = 0; len != minLen; ++len)
    {
      char common = strs[0][len];
      for (int j = 0; j < strs.size(); ++j)
      {
        if (strs[j][len] != common)
          return commonPrefix;
      }
      commonPrefix.push_back(common);
    }

    return commonPrefix;
  }
};

int main(int argc, char* argv[])
{
  std::vector<std::string> strs;
  int num;
  std::cin >> num;

  for (int i = 0; i < num; ++i)
  {
    std::string str;
    std::cin >> str;
    strs.push_back(str);
  }

  Solution s;
  std::cout << s.longestCommonPrefix(strs);

  return 0;
}

