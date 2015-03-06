#include <algorithm>
#include <vector>

class Solution {
public:
  int findPeakElementLinear(const vector<int> &num) {
    if (num.size() <= 1)
      return 0;
    else if (num.size() == 2)
      return num[0] > num[1] ? 0 : 1;

    for (int i = 1; i < num.size() - 1; ++i)
    {
      if (num[i] > num[i - 1] && num[i] > num[i + 1])
        return i;
    }

    return num[0] > num[1] ? 0 : num.size() - 1;
  }

  int findPeakElement(const vector<int> &num) {
    int low = 0;
    int high = num.size() - 1;
    int mid;
    while (low < high)
    {
      mid = (low + high) / 2;
      if (num[mid] < num[mid + 1])
        low = mid + 1;
      else
        high = mid;
    }

    return low;
  }
};
