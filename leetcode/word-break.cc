#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    for (int i = 0; i < s.length(); ++i)
    {
      string str = s.substr(0, i + 1);
      unordered_set<string>::iterator iter;
      if ((iter = dict.find(str)) != dict.end())
      {
        if (!s.substr(i+1).length())
          return true;
        dict.erase(iter);
        if (wordBreak(s.substr(i + 1), dict))
          return true;
        dict.insert(str);
      }
    }

    return false;
  }
};

int main()
{
  string s;
  cin >> s;
  int n;
  cin >> n;
  unordered_set<string> dict;
  for (int i = 0; i < n; ++i)
  {
    string temp;
    cin >> temp;
    dict.insert(temp);
  }

  Solution solution;
  cout << solution.wordBreak(s, dict) << endl;

  return 0;
}

