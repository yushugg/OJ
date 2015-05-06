#include <string>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    wordDict.insert(beginWord);
    unordered_map<string, bool> wordMap;
    for (auto iter = wordDict.begin(); iter != wordDict.end(); ++iter) wordMap.insert(make_pair(*iter, false));
    queue<string> q;
    q.push(beginWord);
    q.push("");
    int count = 1;
    while (!q.empty()) {
      string node = q.front();
      q.pop();
      if (node != "") {
        for (int i = 0; i < beginWord.length(); ++i) {
          for (char c = 'a'; c <= 'z'; ++c) {
            if (node[i] != c) {
              char tmp = node[i];
              node[i] = c;
              if (node == endWord) return count + 1;
              if (wordMap.find(node) != wordMap.end() && !wordMap[node]) {
                wordMap[node] = true;
                q.push(node);
              }
              node[i] = tmp;
            }
          }
        }
      } else {
        if (q.empty()) break;
        ++count;
        q.push("");
      }
    }

    return 0;
  }
};

int main() {
  string beginWord, endWord;
  cin >> beginWord >> endWord;

  int size;
  cin >> size;
  unordered_set<string> wordDict;
  for (int i = 0; i < size; ++i) {
    string word;
    cin >> word;
    wordDict.insert(word);
  }

  Solution solution;
  cout << solution.ladderLength(beginWord, endWord, wordDict) << endl;

  return 0;
}

