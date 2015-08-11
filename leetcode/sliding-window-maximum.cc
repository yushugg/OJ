#include <vector>
#include <cstdio>

using namespace std;

class Solution {
private:
  int findMax(const vector<int>& nums, int start, int end) {
    int maxIdx = start;
    for (int i = start + 1; i < end; ++i) {
      if (nums[i] >= nums[maxIdx]) maxIdx = i;
    }
    return maxIdx;
  }

public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return vector<int>();
    if (k == 1) return vector<int>(nums);

    vector<int> result;
    int maxIdx = findMax(nums, 0, k);
    result.push_back(nums[maxIdx]);
    for (int i = 1; i < nums.size() - k + 1; ++i) {
      if (nums[maxIdx] > nums[i + k - 1]) {
        if (maxIdx == i - 1) maxIdx = findMax(nums, i, i + k);
      } else maxIdx = i + k - 1;
      result.push_back(nums[maxIdx]);
    }

    return result;
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
  vector<int> maxWindows = solution.maxSlidingWindow(nums, k);
  for (int m : maxWindows) printf(" %d", m);
  puts("");

  return 0;
}

