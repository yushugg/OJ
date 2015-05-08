#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    if (s1.length() != s2.length()) return false;
    string tmp1 = s1, tmp2 = s2;
    sort(tmp1.begin(), tmp1.end()); sort(tmp2.begin(), tmp2.end());
    if (tmp1 != tmp2) return false;
    for (int i = 1; i < s1.length(); ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
      if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.length() - i))) return true;
    }
    return false;
  }

  bool isScrambleDP(string s1, string s2) {
    bool dp[s1.length()][s2.length()][s1.length() + 1];
    for (int i = 0; i < s1.length(); ++i) {
      for (int j = 0; j < s2.length(); ++j) {
        for (int k = 0; k < s1.length() + 1; ++k) dp[i][j][k] = false;
      }
    }
    for (int i = 0; i < s1.length(); ++i) {
      for (int j = 0; j < s2.length(); ++j) {
        dp[i][j][1] = s1[i] == s2[j];
        for (int k = 2; i + k <= s1.length() && j + k <= s2.length(); ++k) {
          for (int n = 1; n < k; ++n) {
            dp[i][j][k] |= dp[i][j][n] && dp[i + n][j + n][k - n];
            dp[i][j][k] |= dp[i][j + k - n][n] && dp[i + n][j][k - n];
          }
        }
      }
    }
    return dp[0][0][s1.length()];
  }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  Solution solution;
  cout << solution.isScramble(s1, s2) << endl;

  return 0;
}

