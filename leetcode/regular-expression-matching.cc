#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    if (s.empty()) {
      if (p.empty() || (p.length() == 2 && p[0] != '*' && p[1] == '*')) return true;
      else return false;
    }
    int si = 0, pi = 0;
    while (si < s.length()) {
      switch (p[pi]) {
      case '.':
        if (pi < p.length() - 1 && p[pi + 1] == '*') {
          if (pi == p.length() - 2) return true;
        }
        ++si; ++pi;
        break;
      case '*':
        return false;
      default:
        if (pi < p.length() - 1 && p[pi + 1] == '*') {
          return true;
        }
        else if (s[si] == p[pi]) { ++si; ++pi; }
        else return false;
        break;
      }
    }
    return true;
  }
};

int main() {
  string s, p;
  cin >> s >> p;

  Solution solution;
  cout << solution.isMatch(s, p) << endl;

  return 0;
}

