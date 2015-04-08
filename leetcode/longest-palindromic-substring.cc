#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string str;
    str.push_back('$');
    for (int i = 0; i < s.length(); ++i)
    {
      str.push_back('#');
      str.push_back(s[i]);
    }
    str.push_back('#');

    vector<int> p(str.length(), 0);
    int id, mx; // id: max center index, mx: p[id] + id
    id = mx = 0;
    for (int i = 0; i < str.length(); ++i)
    {
      if (i < mx)
        p[i] = std::min(p[2 * id - i], mx - i);
      else
        p[i] = 1;

      while (str[i + p[i]] == str[i - p[i]])
        ++p[i];

      if (p[i] + i > mx)
      {
        id = i;
        mx = id + p[id];
      }
    }

    int max = 0;
    for (int i = 0; i < str.length(); ++i)
    {
      if (p[max] < p[i])
        max = i;
    }

    string result;
    int start = max - p[max] + 1;
    int end = max + p[max] - 1;
    for (int i = start; i <= end; ++i)
      if (str[i] != '#')
        result.push_back(str[i]);

    return result;
  }
};

int main()
{
  string s;
  cin >> s;
  Solution solution;
  cout << solution.longestPalindrome(s) << endl;

  return 0;
}

