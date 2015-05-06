#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class comp {
public:
  bool operator() (const int& lhs, const int& rhs) const {
    char l[15], r[15];
    sprintf(l, "%d", lhs); sprintf(r, "%d", rhs);
    string ls(l), rs(r);
    if (ls + rs > rs + ls) return false;
    else return true;
    /*for (int i = 0; l[i] != '\0' && r[i] != '\0'; ++i) {
      if (l[i] != r[i]) return l[i] < r[i];
      else if (l[i + 1] == '\0' && r[i + 1] != '\0') {
        if (l[0] > r[i + 1]) return false; else if (l[0] < r[i + 1]) return true; else return false;
      }
      else if (l[i + 1] != '\0' && r[i + 1] == '\0') {
        if (l[i + 1] > r[0]) return false; else if (l[i + 1] < r[0]) return true; else return true;
      }
    }
    return false;*/
  }
};

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    priority_queue<int, vector<int>, comp> queue(nums.begin(), nums.end());
    string result;
    while (!queue.empty()) {
      char s[15];
      sprintf(s, "%d", queue.top());
      result += string(s);
      queue.pop();
    }
    // Find ahead zeros
    int i;
    for (i = 0; i < result.length(); ++i) if (result[i] != '0') break;
    if (i == result.length()) return "0";
    result = result.substr(i, result.length() - i);
    return result;
  }
};

int main() {
  int size;
  cin >> size;
  vector<int> nums;
  for (int i = 0; i < size; ++i) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  Solution s;
  cout << s.largestNumber(nums) << endl;

  return 0;
}

