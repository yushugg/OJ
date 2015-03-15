#include <vector>
#include <algorithm>
#include <cstdio>

class Solution {
public:
  void combination(std::vector<std::vector<int> >& result, std::vector<int> num, int sum, const std::vector<int>& candidates, int end, int target)
  {
    if (sum < target)
    {
      for (int i = end; i >= 0; --i)
      {
        if (num.empty() || num.front() >= candidates[i])
        {
          if (candidates[i] <= target - sum)
          {
            num.push_back(candidates[i]);
            sum += candidates[i];
            combination(result, num, sum, candidates, i, target);
            num.pop_back();
            sum -= candidates[i];
          }
        }
      }
    } else if (sum == target)
    {
      std::reverse(num.begin(), num.end());
      result.push_back(num);
    }
  }

  std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int> > result;
    std::vector<int> num;
    //for (int i = candidates.size() - 1; i >= 0; --i)
    //{
      //if (candidates[i] <= target)
        combination(result, num, 0, candidates, candidates.size() - 1, target);
    //}

    return result;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);

  std::vector<int> candidates;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    candidates.push_back(temp);
  }

  int target;
  scanf("%d", &target);

  Solution s;
  std::vector<std::vector<int> > result = s.combinationSum(candidates, target);
  for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
      printf("%d ", *iter2);
    putchar('\n');
  }

  return 0;
}

