#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    nums.push_back(-1);
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] != -1 && nums[i] != i) {
        int val = nums[i];
        nums[i] = nums[val];
        nums[val] = val;
      }
    }
    return find(nums.begin(), nums.end(), -1) - nums.begin();
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
  printf("%d\n", solution.missingNumber(nums));

  return 0;
}

