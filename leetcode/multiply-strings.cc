#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  string multi(string num, int c) {
    string result;
    int carry = 0;
    for (int i = num.length() - 1; i >= 0; --i) {
      int m = (num[i] - '0') * c + carry;
      result.push_back('0' + m % 10);
      carry = m / 10;
    }

    if (carry) result.push_back('0' + carry);
    while (result.length() > 1 && result.back() == '0') result.pop_back();
    std::reverse(result.begin(), result.end());

    return result;
  }

  string add(string num1, string num2) {
    string result;
    int carry = 0;
    int n1 = num1.length() - 1, n2 = num2.length() - 1;
    while (n1 >= 0 && n2 >= 0) {
      int m = (num1[n1] - '0') + (num2[n2] - '0') + carry;
      result.push_back('0' + m % 10);
      carry = m / 10;
      --n1; --n2;
    }

    while (n1 >= 0) {
      int m = (num1[n1] - '0') + carry;
      result.push_back('0' + m % 10);
      carry = m / 10;
      --n1;
    }

    while (n2 >= 0) {
      int m = (num2[n2] - '0') + carry;
      result.push_back('0' + m % 10);
      carry = m / 10;
      --n2;
    }

    if (carry) result.push_back('0' + carry);
    while (result.length() > 1 && result.back() == '0') result.pop_back();
    std::reverse(result.begin(), result.end());

    return result;
  }

  string multiply(string num1, string num2) {
    string result;

    for (int i = num2.length() - 1; i >= 0; --i) {
      string temp = multi(num1, num2[i] - '0');
      int count = num2.length() - i - 1;
      while (count--) temp.push_back('0');
      result = add(result, temp);
    }

    return result;
  }
};

int main()
{
  string num1, num2;
  cin >> num1 >> num2;

  Solution s;
  cout << s.multiply(num1, num2) << endl;

  return 0;
}

