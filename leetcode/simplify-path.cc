#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string simpath = "/";
    int start = 1;
    if (path[path.length() - 1] != '/') path.push_back('/');
    for (int i = start; i < path.length(); ++i) {
      if (path[i] == '/') {
        if (i > start) {
          string way = path.substr(start, i - start);
          if (way == ".." && simpath != "/") {
            simpath.pop_back();
            for (int j = simpath.length() - 1; simpath[j] != '/'; --j) simpath.pop_back();
          } else if (way != ".." && way != ".") {
            simpath.append(way.begin(), way.end());
            simpath.push_back('/');
          }
        }
        start = i + 1;
      }
    }
    if (simpath != "/") simpath.pop_back();

    return simpath;
  }
};

int main() {
  string path;
  cin >> path;

  Solution solution;
  cout << solution.simplifyPath(path) << endl;

  return 0;
}

