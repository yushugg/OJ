#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void restore(vector<string>& ips, string ip, int ipCount, int start, const string& s) {
    if (ipCount == 4) {
      if (start == s.length()) {
        ip.pop_back();
        ips.push_back(ip);
      }
      return ;
    }
    for (int i = 0; i < 3; ++i) {
      if (start + i >= s.length()) return ;
      if (s[start] == '0' && i > 0) return ;
      if (i == 2 && s.substr(start, i + 1) > string("255")) continue;
      ip += s.substr(start, i + 1);
      ip.push_back('.');
      restore(ips, ip, ipCount + 1, start + i + 1, s);
      for (int j = 0; j < i + 2; ++j) ip.pop_back();
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> ips;
    string ip;
    restore(ips, ip, 0, 0, s);

    return ips;
  }
};

int main() {
  string s;
  cin >> s;
  Solution solution;
  vector<string> ips = solution.restoreIpAddresses(s);

  for (auto iter = ips.begin(); iter != ips.end(); ++iter)
    cout << *iter << endl;

  return 0;
}

