#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  void reverse(string &s, int start, int end) {
    while (start < end)
    {
      char temp = s[start];
      s[start] = s[end];
      s[end] = temp;
      ++start;
      --end;
    }
  }

  void reverseWords(string &s) {
    // Reverse all
    reverse(s, 0, s.length() - 1);

    // Deal with white spaces
    int startPos = -1;
    for (int i = 0; i < s.length(); ++i)
      if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\n') { startPos = i; break; }

    if (startPos == -1) { s = ""; return ; }

    bool space = false;
    int count = 0;
    for (int i = startPos; i < s.length(); ++i) {
      if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\n') { s[count++] = s[i]; space = true; }
      else if (space) { s[count++] = ' '; space = false; }
    }
    int startClear = count;
    if (s[count - 1] == ' ') startClear = count - 1;
    int len = s.length();
    for (int i = startClear; i < len; ++i) s.pop_back();

    // Reverse word by word
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); ++i)
      if (s[i] == ' ') { end = i - 1; reverse(s, start, end); start = i + 1; }
    reverse(s, start, s.length() - 1);
  }
};

int main()
{
  string s = "   the  sky is    blue  ";
  //cin >> s;

  Solution solution;
  solution.reverseWords(s);

  cout << s << endl;

  return 0;
}

