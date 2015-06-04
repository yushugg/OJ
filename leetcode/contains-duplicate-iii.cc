#include <vector>
#include <multimap>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // Construct map
    multimap<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {

    }
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

