#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int step = 0;
    int start = 0, end = 0;
    while (end < nums.size() - 1) {
      ++step;
      int last = end + 1;
      for (int i = start; i <= end; ++i) {
        if (nums[i] + i > last) last = nums[i] + i;
      }
      start = end + 1; end = last;
    }

    return step;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  for (int i = 0; i < size; ++i) { int temp; scanf("%d", &temp); nums.push_back(temp); }

  Solution solution;
  printf("%d\n", solution.jump(nums));

  return 0;
}

