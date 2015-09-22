#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int idx = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i]) nums[idx++] = nums[i];
    }
    for (int i = idx; i < nums.size(); ++i) nums[i] = 0;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  while (size--) {
    int val;
    scanf("%d", &val);
    nums.push_back(val);
  }

  Solution solution;
  solution.moveZeroes(nums);

  for (auto num : nums) printf("%d ", num);
  putchar('\n');

  return 0;
}

