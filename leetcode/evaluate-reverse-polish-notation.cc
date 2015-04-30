#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isOperator(const string& token) {
    if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token.length() > 1)) return false;
    else return true;
  }

  string operate(const string& op1, const string& op2, const string& op) {
    int i1 = atoi(op1.c_str());
    int i2 = atoi(op2.c_str());
    int result;
    switch (op[0]) {
    case '+':
      result = i1 + i2;
      break;
    case '-':
      result = i1 - i2;
      break;
    case '*':
      result = i1 * i2;
      break;
    case '/':
      result = i1 / i2;
      break;
    }
    char c[15];
    sprintf(c, "%d", result);
    return string(c);
  }

  int evalRPN(vector<string>& tokens) {
    stack<string> tokenStack;
    for (int i = 0; i < tokens.size(); ++i) {
      if (isOperator(tokens[i])) {
        string op1 = tokenStack.top();
        tokenStack.pop();
        string op2 = tokenStack.top();
        tokenStack.pop();
        string ret = operate(op2, op1, tokens[i]);
        tokenStack.push(ret);
      } else tokenStack.push(tokens[i]);
    }
    return atoi(tokenStack.top().c_str());
  }
};

int main() {
  int size;
  cin >> size;
  vector<string> tokens;
  for (int i = 0; i < size; ++i) {
    string token;
    cin >> token;
    tokens.push_back(token);
  }

  Solution solution;
  cout << solution.evalRPN(tokens);

  return 0;
}

