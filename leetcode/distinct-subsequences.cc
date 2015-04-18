#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
  int numDistinct(string S, string T) {
    int s = S.length(), t = T.length();
    int *dp = new int[t + 1];
    memset(dp, 0, (t + 1) * sizeof(int));
    dp[0] = 1;

    for (int i = 1; i <= s; ++i) {
      for (int j = t; j >= 1; --j) {
        if (S[i - 1] == T[j - 1]) dp[j] += dp[j - 1];
      }
    }

    int result = dp[t];
    delete[] dp;

    return result;
  }
};

int main() {
  string S, T;
  cin >> S >> T;

  Solution solution;
  cout << solution.numDistinct(S, T) << endl;

  return 0;
}

