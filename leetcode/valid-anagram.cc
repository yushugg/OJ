#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int sc[26], tc[26];
    memset(sc, 0, 26 * sizeof(int));
    memset(tc, 0, 26 * sizeof(int));
    for (int i = 0; i < s.length(); ++i) { ++sc[s[i] - 'a']; ++tc[t[i] - 'a']; }
    for (int i = 0; i < 26; ++i) if (sc[i] != tc[i]) return false;
    return true;
  }
};

int main() {
  string s, t;
  cin >> s >> t;
  Solution solution;
  cout << solution.isAnagram(s, t) << endl;

  return 0;
}

