#include <vector>
#include <unordered_set>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int num : nums) {
      if (set.find(num) == set.end()) set.insert(num);
      else return true;
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

  Solution solution;
  printf("%d\n", solution.containsDuplicate(nums));

  return 0;
}

