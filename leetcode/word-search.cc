#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool visit(vector<vector<char> >& board, int x, int y, int count, const string& word) {
    if (count == word.length()) return true;
    if (x < 0) return false;
    if (x >= board.size()) return false;
    if (y < 0) return false;
    if (y >= board[0].size()) return false;
    if (board[x][y] != word[count]) return false;

    char c = board[x][y];
    board[x][y] = '.';
    bool result = visit(board, x - 1, y, count + 1, word) || visit(board, x + 1, y, count + 1, word) || visit(board, x, y - 1, count + 1, word) || visit(board, x, y + 1, count + 1, word);
    board[x][y] = c;
    return result;
  }

  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) return true;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == word[0]) {
          if (visit(board, i, j, 0, word)) return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<char> > board;
  getchar();
  for (int i = 0; i < m; ++i) {
    vector<char> line;
    for (int j = 0; j < n; ++j) {
      char c = getchar();
      line.push_back(c);
    }
    board.push_back(line);
    getchar();
  }
  string word;
  cin >> word;

  Solution solution;
  cout << solution.exist(board, word) << endl;

  return 0;
}

