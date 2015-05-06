#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool valid(const string& val) {
    if (val[0] == '0') return false;
    if (val.length() == 2 && val > string("26")) return false;
    return true;
  }

  void decode(int& count, int start, const string& s) {
    if (start >= s.length()) ++count;
    for (int i = 0; i < 2 && start + i + 1 <= s.length(); ++i) {
      string val = s.substr(start, i + 1);
      if (valid(val)) decode(count, start + i + 1, s);
    }
  }

  int numDecodingsWithBacktracking(string s) {
    int count = 0;
    decode(count, 0, s);
    return count;
  }

  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    if (s.length() == 1) return 1;
    int ways[s.length()];
    ways[0] = 1;
    if (s[1] == '0') if (s.substr(0, 2) > string("26")) return 0; else ways[1] = 1;
    else ways[1] = s.substr(0, 2) > string("26") ? 1 : 2;
    //cout << ways[1] << endl;
    for (int i = 2; i < s.length(); ++i) {
      if (s[i] == '0') {
        if (s[i - 1] == '0') return 0;
        else if (s.substr(i - 1, 2) > string("26")) return 0;
        else return ways[i] = ways[i - 2];
      } else {
        if (s[i - 1] == '0') if (i > 2) ways[i] = ways[i - 3]; else ways[i] = 1;
        else if (s.substr(i - 1, 2) > string("26")) ways[i] = ways[i - 1];
        else ways[i] = ways[i - 1] + ways[i - 2];
      }
    }
    return ways[s.length() - 1];
  }
};

int main() {
  string s;
  cin >> s;

  Solution solution;
  cout << solution.numDecodings(s) << endl;

  return 0;
}

