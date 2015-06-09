#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    int result = 0;
    bool sign = true;
    stack<bool> st;
    st.push(true);
    int i = 0;
    while (i < s.length()) {
      char c = s[i];
      switch (c) {
      case ' ':
        ++i;
        break;
      case '-':
        sign = false; ++i;
        break;
      case '+':
        sign = true; ++i;
        break;
      case '(':
        if (sign) st.push(st.top());
        else st.push(!st.top());
        sign = true; ++i;
        break;
      case ')':
        st.pop(); ++i;
        break;
      default:
        int num = 0, j = i;
        while (j < s.length() && s[j] >= '0' && s[j] <= '9')
          num = num * 10 + (s[j++] - '0');
        if ((!st.top() && sign) || (st.top() && !sign)) result -= num;
        else result += num;
        i = j;
        break;
      }
    }
    return result;
  }
};

int main() {
  string s;
  Solution solution;
  while (cin >> s) {
    cout << solution.calculate(s) << endl;
  }

  return 0;
}

