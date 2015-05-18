#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> indexStack;
    int longest = 0;
    int bottom = -1;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') indexStack.push(i);
      else {
        if (indexStack.empty()) bottom = i;
        else {
          indexStack.pop();
          if (indexStack.empty()) longest = max(longest, i - bottom);
          else longest = max(longest, i - indexStack.top());
        }
      }
    }
    return longest;
  }
};

int main() {
  string s;
  Solution solution;
  while (cin >> s) cout << solution.longestValidParentheses(s) << endl;

  return 0;
}

