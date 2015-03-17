#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

class Solution {
public:
  int threeSumClosest(std::vector<int> &num, int target) {
    std::sort(num.begin(), num.end());
    int closest = num[0] + num[1] + num[2];
    for (int i = 0; i < num.size() - 2; ++i)
    {
      int start = i + 1;
      int end = num.size() - 1;
      while (start < end)
      {
        if (fabs(num[i] + num[start] + num[end] - target) < fabs(closest - target))
          closest = num[i] + num[start] + num[end];

        if (num[i] + num[start] + num[end] < target)
          ++start;
        else if (num[i] + num[start] + num[end] > target)
          --end;
        else
          return target;
      }
    }

    return closest;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  std::vector<int> num;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    num.push_back(temp);
  }
  int target;
  scanf("%d", &target);

  Solution s;
  printf("%d\n", s.threeSumClosest(num, target));

  return 0;
}

