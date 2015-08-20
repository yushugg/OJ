#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int temp = 0;
    for (int num : nums) temp ^= num;
    int flag = 1;
    while (!(temp & flag)) flag <<= 1;
    int single1 = 0, single2 = 0;
    for (int num : nums) {
      if (num & flag) single1 ^= num;
      else single2 ^= num;
    }
    vector<int> result;
    result.push_back(single1);
    result.push_back(single2);
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
  vector<int> singleNumbers = solution.singleNumber(nums);
  for (int num : singleNumbers) cout << num << "\n";

  return 0;
}

