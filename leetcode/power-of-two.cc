#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isPowerOfTwoWithSet(int n) {
    unordered_set<int> set;
    for (int i = 0; i < 31; ++i) set.insert(1 << i);
    return set.find(n) != set.end();
  }

  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return !(n & (n - 1));
  }
};

int main() {
  int n;
  cin >> n;
  Solution solution;
  cout << solution.isPowerOfTwo(n) << endl;

  return 0;
}

