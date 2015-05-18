#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  void solve(vector<vector<char>>& board, vector<vector<char>> b, bool exist[][9][9], int i, int j) {
    if (i == 9) {
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          board[i][j] = b[i][j];
        }
      }
      return ;
    }
    if (i < 9 && j < 9 && b[i][j] != '.') { solve(board, b, exist, i, j + 1); return ; }
    if (j == 9) { ++i; j = 0; solve(board, b, exist, i, j); return ; }
    int row = i / 3, col = j / 3;
    for (int k = 1; k <= 9; ++k) {
      if (!exist[0][i][k - 1] && !exist[1][j][k - 1] && !exist[2][row * 3 + col][k - 1]) {
        b[i][j] = '0' + k;
        exist[0][i][k - 1] = true;
        exist[1][j][k - 1] = true;
        exist[2][row * 3 + col][k - 1] = true;
        solve(board, b, exist, i, j + 1);
        b[i][j] = '.';
        exist[0][i][k - 1] = false;
        exist[1][j][k - 1] = false;
        exist[2][row * 3 + col][k - 1] = false;
      }
    }
  }

  void solveSudoku(vector<vector<char>>& board) {
    // (3: row, col, grid) * (9: 9 rows, 9 cols, 9 grids) * (9: 9 numbers)
    bool exist[3][9][9];
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 9; ++j) for (int k = 0; k < 9; ++k) exist[i][j][k] = false;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] != '.') {
          exist[0][i][board[i][j] - '1'] = true;
          exist[1][j][board[i][j] - '1'] = true;
          int row = i / 3, col = j / 3;
          exist[2][row * 3 + col][board[i][j] - '1'] = true;
        }
      }
    }
    vector<vector<char> > b = board;
    solve(board, b, exist, 0, 0);
  }
};

int main() {

  return 0;
}

