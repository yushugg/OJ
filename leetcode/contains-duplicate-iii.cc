#include <vector>
#include <climits>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k < 1 || t < 0) return false;
    // Construct map
    unordered_map<long, long> map;
    for (int i = 0; i < nums.size(); ++i) {
      long num = (long)nums[i] - INT_MIN;
      long bucket = num / (long(t) + 1);
      if (map.find(bucket) != map.end() || 
        (map.find(bucket - 1) != map.end() && num - map[bucket - 1] <= t) ||
        (map.find(bucket + 1) != map.end() && map[bucket + 1] - num <= t))
        return true;
      // Remove previous value
      if (map.size() >= k) map.erase(((long)nums[i - k] - INT_MIN) / (long(t) + 1));
      map.emplace(bucket, num);
    }
    return false;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> nums;
  while (size--) {
    int num;
    scanf("%d", &num);
    nums.push_back(num);
  }
  int k, t;
  scanf("%d%d", &k, &t);

  Solution solution;
  printf("%d\n", solution.containsNearbyAlmostDuplicate(nums, k, t));

  return 0;
}

