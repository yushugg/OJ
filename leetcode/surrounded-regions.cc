#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

void printBoard(const vector<vector<char> >& board) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      putchar(board[i][j]);
    }
    puts("");
  }
}

class Solution {
public:
  void dfs(int i, int j, vector<vector<char> >& board) {
    if (i == -1 || i == board.size() || j == -1 || j == board[0].size()) return ;
    if (board[i][j] == 'O') {
      board[i][j] = 'Y';
      dfs(i + 1, j, board);
      dfs(i, j + 1, board);
      dfs(i - 1, j, board);
      dfs(i, j - 1, board);
    }
  }

  void bfs(int i, int j, vector<vector<char> >& board) {
    queue<vector<int> > q;
    vector<int> vec; vec.push_back(i); vec.push_back(j);
    board[i][j] = 'Y';
    q.push(vec);
    while (!q.empty()) {
      vector<int> node = q.front();
      q.pop();
      int x = node[0]; int y = node[1];
      if (x - 1 >= 0 && board[x - 1][y] == 'O') {
        vector<int> v; v.push_back(x - 1); v.push_back(y);
        q.push(v);
        board[x - 1][y] = 'Y';
      }
      if (x + 1 < board.size() && board[x + 1][y] == 'O') {
        vector<int> v; v.push_back(x + 1); v.push_back(y);
        q.push(v);
        board[x + 1][y] = 'Y';
      }
      if (y - 1 >= 0 && board[x][y - 1] == 'O') {
        vector<int> v; v.push_back(x); v.push_back(y - 1);
        q.push(v);
        board[x][y - 1] = 'Y';
      }
      if (y + 1 < board[0].size() && board[x][y + 1] == 'O') {
        vector<int> v; v.push_back(x); v.push_back(y + 1);
        q.push(v);
        board[x][y + 1] = 'Y';
      }
    }
  }

  void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return ;
    for (int i = 0; i < board.size(); ++i) if (board[i][0] == 'O') bfs(i, 0, board);
    for (int i = 0; i < board.size(); ++i) if (board[i][board[0].size() - 1] == 'O') bfs(i, board[0].size() - 1, board);
    for (int i = 0; i < board[0].size(); ++i) if (board[0][i] == 'O') bfs(0, i, board);
    for (int i = 0; i < board[0].size(); ++i) if (board[board.size() - 1][i] == 'O') bfs(board.size() - 1, i, board);
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'Y') board[i][j] = 'O';
        else board[i][j] = 'X';
      }
    }
  }

  void solveWithDFS(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return ;
    for (int i = 0; i < board.size(); ++i) if (board[i][0] == 'O') dfs(i, 0, board);
    //printBoard(board);
    for (int i = 0; i < board.size(); ++i) if (board[i][board[0].size() - 1] == 'O') dfs(i, board[0].size() - 1, board);
    for (int i = 0; i < board[0].size(); ++i) if (board[0][i] == 'O') dfs(0, i, board);
    for (int i = 0; i < board[0].size(); ++i) if (board[board.size() - 1][i] == 'O') dfs(board.size() - 1, i, board);
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'Y') board[i][j] = 'O';
        else board[i][j] = 'X';
      }
    }
  }
};

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

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

  Solution solution;
  solution.solve(board);
  puts("");
  printBoard(board);

  return 0;
}

