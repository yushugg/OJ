#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    if (!s.length())
      return 0;

    int *startPos = new int[s.length()];
    std::unordered_map<char, int> index;

    startPos[0] = 0;
    index.insert(std::make_pair(s[0], 0));
    for (int i = 1; i < s.length(); ++i)
    {
      auto iter = index.find(s[i]);
      if (iter == index.end())
      {
        // Not found
        startPos[i] = startPos[i - 1];
        index.insert(std::make_pair(s[i], i));
      }
      else
      {
        int len = iter->second;
        for (int j = startPos[i - 1]; j <= len; ++j)
          index.erase(s[j]);
        startPos[i] = len + 1;
        index.insert(std::make_pair(s[i], i));
      }
    }

    int max = 0;
    for (int i = 0; i < s.length(); ++i)
    {
      if (max < i - startPos[i] + 1)
        max = i - startPos[i] + 1;
    }

    return max;
  }
};

int main()
{
  std::string str;
  std::cin >> str;
  Solution s;
  std::cout << s.lengthOfLongestSubstring(str) << std::endl;

  return 0;
}

