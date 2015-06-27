#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    int start = 0;
    vector<string> result;
    for (int i = 1; i <= nums.size(); ++i) {
      if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
        if (i - 1 == start) result.push_back(to_string(nums[start]));
        else result.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
        start = i;
      }
    }
    return result;
  }
};

int main() {
  int size;
  cin >> size;
  vector<int> nums;
  while (size--) {
    int val;
    cin >> val;
    nums.push_back(val);
  }

  Solution solution;
  vector<string> result = solution.summaryRanges(nums);

  for (string s : result) {
    cout << s << endl;
  }

  return 0;
}

