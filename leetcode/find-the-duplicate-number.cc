#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {

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
  printf("%d\n", solution.findDuplicate(nums));

  return 0;
}

