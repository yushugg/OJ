#include <cstdio>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int digitSum(int n) {
    int sum = 0;
    while (n) {
      int digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }

    return sum;
  }

  bool isHappy(int n) {
    unordered_set<int> nums;

    while (true) {
      int sum = digitSum(n);
      if (sum == 1) return true;
      else if (nums.find(sum) != nums.end()) return false;
      else nums.insert(sum);
      n = sum;
    }

    return false;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  Solution solution;
  printf("%d\n", solution.isHappy(n));

  return 0;
}
