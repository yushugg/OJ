#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  bool isPalindrome(std::string s, int start, int end)
  {
    while (start < end)
    {
      if (s[start] != s[end])
        return false;
      else
      {
        ++start;
        --end;
      }
    }

    return true;
  }

  void part(std::vector<std::vector<std::string> >& result, std::vector<std::string> thisPart, int thisSize, std::string s) {
    if (thisSize == s.length())
      result.push_back(thisPart);
    else
    {
      for (int i = thisSize; i < s.length(); ++i)
      {
        // If it is a palindrome
        if (isPalindrome(s, thisSize, i))
        {
          std::string thisStr = s.substr(thisSize, i - thisSize + 1);
          thisPart.push_back(thisStr);
          thisSize += thisStr.length();
          part(result, thisPart, thisSize, s);
          thisPart.pop_back();
          thisSize -= thisStr.length();
        }
      }
    }
  }

  std::vector<std::vector<std::string> > partition(std::string s) {
    std::vector<std::vector<std::string> > result;
    std::vector<std::string> thisPart;

    part(result, thisPart, 0, s);

    return result;
  }
};

int main(int argc, char* argv[])
{
  std::string s;
  std::cin >> s;

  Solution solution;
  std::vector<std::vector<std::string> > result = solution.partition(s);

  for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1)
  {
    std::cout << "[";
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
      std::cout << *iter2 << ",";
    std::cout << "]" << std::endl;
  }

  return 0;
}

