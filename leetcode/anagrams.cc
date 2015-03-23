#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    vector<string> result;

    vector<string> sortedStrs = strs;
    unordered_map<string, vector<int> > strMap;
    for (int i = 0; i < strs.size(); ++i)
    {
      std::sort(sortedStrs[i].begin(), sortedStrs[i].end());
      strMap[sortedStrs[i]].push_back(i);
    }

    for (auto iter = strMap.begin(); iter != strMap.end(); ++iter)
    {
      if (iter->second.size() > 1)
      {
        for (auto it = iter->second.begin(); it != iter->second.end(); ++it)
          result.push_back(strs[*it]);
      }
    }

    return result;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<string> strs;
  for (int i = 0; i < n; ++i)
  {
    string str;
    cin >> str;
    strs.push_back(str);
  }

  Solution s;
  vector<string> result = s.anagrams(strs);

  for (int i = 0; i < result.size(); ++i)
    cout << result[i] << " ";
  cout << '\n';

  return 0;
}

