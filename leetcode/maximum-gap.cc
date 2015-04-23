#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    vector<int> buckets[10];
    int radix = 10;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        int index;
        if (radix > 0) index = nums[j] % radix / (radix / 10);
        else index = nums[j] / 1000000000;
        buckets[index].push_back(nums[j]);
      }
      // Put back and clear
      int count = 0;
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < buckets[j].size(); ++k) {
          nums[count++] = buckets[j][k];
        }
        buckets[j].clear();
      }
      radix *= 10;
    }

    int max = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] > max) max = nums[i] - nums[i - 1];
    }

    return max;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  for (int i = 0; i < size; ++i) { int temp; scanf("%d", &temp); nums.push_back(temp); }

  Solution solution;
  printf("%d\n", solution.maximumGap(nums));

  return 0;
}

