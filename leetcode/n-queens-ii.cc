#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool testSafe(const vector<string> &solution, int i, int j, int n) {
    if (i < 0) return true;
    bool safe = true;
    for (int m = 0; m < i; ++m) if (solution[m][j] == 'Q') { safe = false; break; }
    int row = i - 1, col = j - 1;
    while (row >= 0 && col >= 0) if (solution[row--][col--] == 'Q') { safe = false; break; }
    row = i - 1; col = j + 1;
    while (row >= 0 && col < n) if (solution[row--][col++] == 'Q') { safe = false; break; }

    return safe;
  }

  void solve(vector<vector<string> > &result, vector<string> &oneSolution, int i, int j, int n) {
    if (testSafe(oneSolution, i, j, n)) {
      if (i == n - 1) { result.push_back(oneSolution); return ; }
      // iterate
      for (int m = 0; m < n; ++m) {
        string str;
        for (int k = 0; k < m; ++k) str.push_back('.');
        str.push_back('Q');
        for (int k = m + 1; k < n; ++k) str.push_back('.');
        oneSolution.push_back(str);

        solve(result, oneSolution, i + 1, m, n);

        // Backtracking
        oneSolution.pop_back();
      }
    }
  }

  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    vector<string> oneSolution;
    solve(result, oneSolution, -1, 0, n);

    return result;
  }

  int totalNQueens(int n) {
    return solveNQueens(n).size();
  }
};

int main()
{
  int n;
  cin >> n;

  Solution s;
  cout << s.totalNQueens(n) << endl;
  /*vector<vector<string> > result = s.solveNQueens(n);
  for (auto iter = result.begin(); iter != result.end(); ++iter) {
    for (auto it = iter->begin(); it != iter->end(); ++it) cout << *it << endl;
    cout << endl;
  }*/

  return 0;
}

