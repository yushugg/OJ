#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(nums[i]) == map.end()) map.insert(make_pair(nums[i], i));
      else if (i - map[nums[i]] <= k) return true;
      else map[nums[i]] = i;
    }
    return false;
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
  printf("%d\n", solution.containsNearbyDuplicate(nums, k));

  return 0;
}

