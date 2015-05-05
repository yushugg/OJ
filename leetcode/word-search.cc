#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Item {
  int x;
  int y;
  bool visited;
};

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    unordered_multimap<char, Item> map;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        Item item;
        item.x = i;
        item.y = j;
        item.visited = false;
        map.insert(make_pair(board[i][j], item));
      }
    }

    for (int i = 0; i < word.length(); ++i) {
      auto range = map.equal_range(word[i]);
      for (auto iter = range.first; iter != range.second; ++iter) {
        cout << iter->second.x << "," << iter->second.y << ": " << iter->second.visited << " ";
      }
      cout << endl;
    }

    return true;
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

