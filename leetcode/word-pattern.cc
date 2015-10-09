#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> map;
    unordered_set<string> only;
    int str_idx = 0, i;
    for (i = 0; i < pattern.length(); ++i) {
      if (str_idx >= str.length()) break;
      int white_idx = str.find(' ', str_idx);
      if (white_idx == string::npos) white_idx = str.length();
      string sub_str = str.substr(str_idx, white_idx - str_idx);
      str_idx = white_idx + 1;
      if (map.find(pattern[i]) != map.end()) {
        // exist in map
        if (map[pattern[i]] != sub_str) return false;
      } else {
        // not exist in map
        if (only.find(sub_str) != only.end()) return false;
        map[pattern[i]] = sub_str;
        only.insert(sub_str);
      }
    }
    return str_idx == str.length() + 1 && i == pattern.length();
  }
};

int main() {
  string pattern, str = "dog dog dog dog";
  cin >> pattern;

  Solution solution;
  cout << solution.wordPattern(pattern, str) << endl;

  return 0;
}

