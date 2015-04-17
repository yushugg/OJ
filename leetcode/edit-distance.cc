#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    if (!m) return n; if (!n) return m;
    int **table = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i) table[i] = new int[n + 1];
    for (int i = 0; i <= m; ++i) table[i][0] = i;
    for (int i = 0; i <= n; ++i) table[0][i] = i;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        int cost = word1[i - 1] == word2[j - 1] ? 0 : 1;
        table[i][j] = min(min(table[i - 1][j] + 1, table[i][j - 1] + 1), table[i - 1][j - 1] + cost);
      }
    }
    int result = table[m][n];
    for (int i = 0; i <= m; ++i) delete[] table[i];
    delete[] table;

    return result;
  }
};

int main() {
  string word1, word2;
  cin >> word1 >> word2;

  Solution s;
  cout << s.minDistance(word1, word2) << endl;

  return 0;
}
