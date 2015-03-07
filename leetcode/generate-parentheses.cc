#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
  void generateNext(std::vector<std::string>& result, std::string str, char c, int n, int leftCount, int rightCount) {
    if (c == '(') {
      if (leftCount < n) {
        str.push_back('(');
        ++leftCount;
      } else {
        return ;
      }
    } else {
      if (rightCount < leftCount) {
        str.push_back(')');
        ++rightCount;
      } else {
        return ;
      }
    }

    if (leftCount == n && rightCount == n) {
      result.push_back(str);
      return ;
    }

    generateNext(result, str, '(', n, leftCount, rightCount);
    generateNext(result, str, ')', n, leftCount, rightCount);
  }

  std::vector<std::string> generateParenthesis(int n) {
    int leftCount = 0;
    int rightCount = 0;

    std::vector<std::string> result;
    generateNext(result, "", '(', n, leftCount, rightCount);

    return result;
  }
};

int main(int argc, char* argv[])
{
  int n;
  std::cin >> n;

  Solution s;
  std::vector<std::string> result = s.generateParenthesis(n);

  for (auto iter = result.begin(); iter != result.end(); ++iter) {
    std::cout << *iter << std::endl;
  }

  return 0;
}

