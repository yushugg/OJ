#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() <= 3) return *max_element(nums.begin(), nums.end());
    int maxProfit = 0;
    vector<int> money(nums.size(), 0);
    // not rob n-1, 0..n-2
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (i <= 1) money[i] = nums[i];
      else if (i == 2) money[i] = nums[i - 2] + nums[i];
      else money[i] = max(money[i - 2], money[i - 3]) + nums[i];
    }
    maxProfit = max(maxProfit, max(money[nums.size() - 2], money[nums.size() - 3]));

    // not rob 0, 1..n-1
    money.assign(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i) {
      if (i <= 2) money[i] = nums[i];
      else if (i == 3) money[i] = nums[i - 2] + nums[i];
      else money[i] = max(money[i - 2], money[i - 3]) + nums[i];
    }
    maxProfit = max(maxProfit, max(money[nums.size() - 1], money[nums.size() - 2]));

    return maxProfit;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  while (size--) {
    int num;
    scanf("%d", &num);
    nums.push_back(num);
  }

  Solution solution;
  printf("%d\n", solution.rob(nums));

  return 0;
}

