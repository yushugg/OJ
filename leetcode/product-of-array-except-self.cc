#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> output(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) output[i] = output[i - 1] * nums[i - 1];
    int right = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      right *= nums[i + 1];
      output[i] *= right;
    }
    return output;
  }
};

int main() {
  int size;
  cin >> size;
  vector<int> nums;
  while (size--) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  Solution solution;
  vector<int> result = solution.productExceptSelf(nums);
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

