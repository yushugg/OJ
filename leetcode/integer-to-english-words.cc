#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string numberToWords(int num) {
    string num_str[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string teen_str[] = {"Ten", "Tweleve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string ty_str[] = {"Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string mi_str[] = {"", "Thousand", "Million", "Billion"}

    string str = to_string(num);
    int i = 0;
    int iter = (str.length() - 1) / 3;
    string result;
    while (i < str.length()) {
      if (i == 0) {
      } else {
        if (str[i] != 0) {
          result += num_str[str[i] - '0'];
          result += " Hundred";
        }

        --iter;
        i += 3;
      }
    }

    return result;
  }
};

int main() {
  int num;
  cin >> num;
  Solution solution;
  cout << solution.numberToWords(num) << "\n";

  return 0;
}

