#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
  int stoi(const string& str) {
    int num = 0;
    for (int i = 0; i < str.length(); ++i) {
      num = num * 10 + (str[i] - '0');
    }
    return num;
  }

public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> ways;
    for (int i = 0; i < input.length(); ++i) {
      char c = input[i];
      if (c == '+' || c == '-' || c == '*') {
        vector<int> prev = diffWaysToCompute(input.substr(0, i));
        vector<int> post = diffWaysToCompute(input.substr(i + 1));
        for (int pr : prev) {
          for (int po : post)
            ways.push_back(c == '+' ? pr + po : c == '-' ? pr - po : pr * po);
        }
      }
    }
    if (ways.empty()) ways.push_back(stoi(input));
    return ways;
  }
};

int main() {
  string input;
  Solution solution;
  while (cin >> input) {
    vector<int> ways = solution.diffWaysToCompute(input);
    for (int way : ways) cout << " " << way << endl;
    cout << endl;
  }

  return 0;
}

