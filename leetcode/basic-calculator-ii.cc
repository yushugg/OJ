#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isNumber(char c) {
    return c <= '9' && c >= '0';
  }

  bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
  }

  int calculate(string s) {
    vector<long> nums;
    vector<char> ops;
    int i = 0;
    while (i < s.length() && s[i] == ' ') ++i;
    int start = i;
    if (start == s.length()) return 0;
    while (i < s.length() && isNumber(s[i])) ++i;
    if (start < s.length()) {
      if (s.substr(start, i - start) == "2147483648") nums.push_back(2147483648);
      else nums.push_back(stoi(s.substr(start, i - start)));
    }
    while (i < s.length()) {
      if (s[i] == ' ') ++i;
      else if (isOp(s[i])) { ops.push_back(s[i]); ++i; }
      else {
        start = i;
        while (i < s.length() && isNumber(s[i])) ++i;
        if (s.substr(start, i - start) == "2147483648") nums.push_back(2147483648);
        else nums.push_back(stoi(s.substr(start, i - start)));
      }
    }

    vector<long> addNums;
    vector<char> addOps;
    addNums.push_back(nums[0]);
    for (int i = 0; i < ops.size(); ++i) {
      if (ops[i] == '+' || ops[i] == '-') {
        addNums.push_back(nums[i + 1]);
        addOps.push_back(ops[i]);
      } else {
        long left = addNums.back();
        addNums.pop_back();
        if (ops[i] == '*') addNums.push_back(left * nums[i + 1]);
        else addNums.push_back(left / nums[i + 1]);
      }
    }

    long result = addNums[0];
    for (int i = 0; i < addOps.size(); ++i) {
      if (addOps[i] == '+') result += addNums[i + 1];
      else result -= addNums[i + 1];
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

