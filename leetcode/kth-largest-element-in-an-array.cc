#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int iteration(vector<int>& nums, int start, int end, int k) {
    int left = start + 1, right = end;
    while (true) {
      while (left <= end && nums[left] <= nums[start]) ++left;
      while (right >= start && nums[right] >= nums[start]) --right;
      if (left < right) swap(nums[left], nums[right]);
      else break;
    }
    if (right >= start) swap(nums[right], nums[start]);
    else right = start;
    if (right == nums.size() - k) return nums[right];
    else if (right < nums.size() - k) return iteration(nums, right + 1, end, k);
    else return iteration(nums, start, right - 1, k);
  }

  int findKthLargest(vector<int>& nums, int k) {
    return iteration(nums, 0, nums.size() - 1, k);
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
  int k;
  scanf("%d", &k);

  Solution solution;
  printf("%d\n", solution.findKthLargest(nums, k));

  return 0;
}

