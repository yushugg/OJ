#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int a, b, ca = 0, cb = 0;
    for (int num : nums) {
      if (a == num) ++ca;
      else if (b == num) ++cb;
      else if (!ca) a = num, ++ca;
      else if (!cb) b = num, ++cb;
      else --ca, --cb;
    }
    ca = 0, cb = 0;
    for (int num : nums) {
      if (num == a) ++ca;
      else if (num == b) ++cb;
    }

    vector<int> result;
    if (ca > nums.size() / 3) result.push_back(a);
    if (cb > nums.size() / 3) result.push_back(b);

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
  vector<int> majors = solution.majorityElement(nums);
  for (int e : majors) cout << e << " ";
  cout << endl;

  return 0;
}

