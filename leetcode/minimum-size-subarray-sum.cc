#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty() || s <= 0) return 0;
    int start = 0, end = 0;
    int sum = nums[0];
    int minLen = nums.size() + 1;
    while (end < nums.size()) {
      if (sum >= s) {
        minLen = min(minLen, end - start + 1);
        sum -= nums[start];
        ++start;
      }
      else if (end < nums.size()) sum += nums[++end];
    }
    return minLen > nums.size() ? 0 : minLen;;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  for (int i = 0; i < size; ++i) {
    int val;
    scanf("%d", &val);
    nums.push_back(val);
  }
  int s;
  scanf("%d", &s);

  Solution solution;
  printf("%d\n", solution.minSubArrayLen(s, nums));

  return 0;
}

