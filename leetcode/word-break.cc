#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    bool *canBreak = new bool[s.length() + 1];
    for (int i = 1; i < s.length() + 1; ++i)
      canBreak[i] = false;
    canBreak[0] = true;

    for (int i = 1; i < s.length() + 1; ++i)
    {
      for (int j = 1; j <= i; ++j)
      {
        if (canBreak[j - 1] && dict.find(s.substr(j - 1, i - j + 1)) != dict.end())
        {
          canBreak[i] = true;
          break;
        }
      }
    }

    return canBreak[s.length()];
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

