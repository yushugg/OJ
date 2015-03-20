#include <vector>
#include <algorithm>

class Solution {
public:
  void combination(std::vector<std::vector<int> >& result, std::vector<int> num, int start, int sum, const std::vector<int>& numSet, int target)
  {
    if (sum == target)
      result.push_back(num);
    else
    {
      for (int i = start; i < numSet.size(); ++i)
      {
        if (sum + numSet[i] <= target && (i == start || numSet[i] != numSet[i - 1]))
        {
          num.push_back(numSet[i]);
          combination(result, num, i + 1, sum + numSet[i], numSet, target);
          num.pop_back();
        }
      }
    }
  }

  std::vector<std::vector<int> > combinationSum2(std::vector<int> &num, int target) {
    std::sort(num.begin(), num.end());
    
    std::vector<std::vector<int> > result;
    std::vector<int> one;

    combination(result, one, 0, 0, num, target);

    return result;
  }
};
