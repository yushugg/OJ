#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    if (count_if(p.begin(), p.end(), [](char c)->bool { return c!= '*'; }) > s.size()) 
      return false;
    vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= p.length(); ++j)
      dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];
    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 1; j <= p.length(); ++j) {
        if (p[j - 1] != '*')
          dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '?' == p[j - 1]);
        else
          dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
      }
    }

    return dp[s.length()][p.length()];
  }
};

int main() {
  string s, p;
  Solution solution;
  while (true) {
    cin >> s >> p;
    cout << solution.isMatch(s, p) << endl;
  }

  return 0;
}

