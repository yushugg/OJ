#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, char> map;
    unordered_set<char> set;
    for (int i = 0; i < s.length(); ++i) {
      if (map.find(s[i]) != map.end() && map[s[i]] != t[i]) return false;
      else if (map.find(s[i]) == map.end()) { 
        if (set.find(t[i]) == set.end()) {
          map.insert(make_pair(s[i], t[i]));
          set.insert(t[i]);
        }
        else return false;
      }
    }
    return true;
  }
};

int main() {
  string s, t;
  cin >> s >> t;

  Solution solution;
  cout << solution.isIsomorphic(s, t) << endl;

  return 0;
}

