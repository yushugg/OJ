#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (!numerator) return "0";
    bool sign = (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0);
    long nu = numerator, de = denominator;
    if (nu < 0) nu = -nu;
    if (de < 0) de = -de;
    string result;
    bool decimal = false;
    unordered_map<long, int> map;
    while (nu) {
      long val = nu / de;
      char c[15];
      sprintf(c, "%ld", val);
      result += string(c);
      if (decimal) {
        if (map.find(nu) == map.end()) map.insert(make_pair(nu, result.size() - 1));
        else {
          int start, length;
          start = map[nu]; length = result.size() - 1 - start;
          return sign ? result.substr(0, start) + "(" + result.substr(start, length) + ")" : "-" + result.substr(0, start) + "(" + result.substr(start, length) + ")";
        }
      }
      nu -= val * de;
      nu *= 10;
      if (!decimal && nu) { result += "."; decimal = true; }
    }

    return sign ? result : "-" + result;
  }
};

int main() {
  int numerator, denominator;
  cin >> numerator >> denominator;

  Solution s;
  cout << s.fractionToDecimal(numerator, denominator);

  return 0;
}

