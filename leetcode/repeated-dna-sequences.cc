#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    unordered_map<size_t, int> map;
    hash<string> hashFn;
    for (int i = 0; i + 9 < s.length(); ++i) {
      string str = s.substr(i, 10);
      size_t key = hashFn(str);
      if (map.find(key) == map.end()) {
        map.insert(make_pair(key, 1));
      } else {
        if (map[key] == 1) result.push_back(str);
        ++map[key];
      }
    }

    return result;
  }
};

int main() {
  string s;
  cin >> s;

  Solution solution;
  vector<string> result = solution.findRepeatedDnaSequences(s);
  for (auto iter = result.begin(); iter != result.end(); ++iter) cout << *iter << endl;

  return 0;
}

