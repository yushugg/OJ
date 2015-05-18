#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatchRecursively(string s, string p) {
    if (p.empty()) return s.empty();
    if (p[1] != '*')
      return !s.empty() && ((s[0] == p[0] || '.' == p[0]) && isMatchRecursively(s.substr(1), p.substr(1)));
    else
      return isMatchRecursively(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatchRecursively(s.substr(1), p));
  }

  bool isMatch(string s, string p) {
    vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
    dp[0][0] = true;
    // len(s) == 0, j - 1 means current pos, j means length
    // Only x*y* suitable for len(s) == 0
    for (int j = 1; j <= p.length(); ++j)
      dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 1; j <= p.length(); ++j) {
        if (p[j - 1] != '*')
          dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
        else
          dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j]);
      }
    }

    return dp[s.length()][p.length()];
  }
};

int main() {
  string s, p;
  while (true) {
    cin >> s >> p;

    Solution solution;
    cout << solution.isMatchRecursively(s, p) << endl;
  }

  return 0;
}

