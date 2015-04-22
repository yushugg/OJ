#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] != i + 1) return i + 1;

    return nums.size() + 1;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  for (int i = 0; i < size; ++i) { int temp; scanf("%d", &temp); nums.push_back(temp); }

  Solution solution;
  printf("%d\n", solution.firstMissingPositive(nums));

  return 0;
}

