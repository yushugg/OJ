#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return vector<int>();
    if (k == 1) return vector<int>(nums);
    unordered_set<int> set;
    vector<int> result;
    int maxVal = *max_element(nums.begin(), nums.begin() + k);
    result.push_back(maxVal);
    for (int i = 0; i < k; ++i) {
      if (maxVal == nums[i]) set.insert(i);
    }

    for (int i = 1; i < nums.size() - k + 1; ++i) {
      int front = i - 1, end = i + k - 1;
      if (nums[front] == result.back()) 
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

