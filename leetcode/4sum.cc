#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target) {
    std::sort(num.begin(), num.end());

    std::vector<std::vector<int> > result;
    for (int i = 0; i < num.size(); ++i)
    {
      if (i > 0 && num[i] == num[i - 1])
        continue;
      for (int j = i + 1; j < num.size(); ++j)
      {
        if (j > i + 1 && num[j] == num[j - 1])
          continue;
        int low = j + 1;
        int high = num.size() - 1;
        while (low < high)
        {
          if (num[i] + num[j] + num[low] + num[high] == target)
          {
            std::vector<int> temp;
            temp.push_back(num[i]);
            temp.push_back(num[j]);
            temp.push_back(num[low]);
            temp.push_back(num[high]);

            result.push_back(temp);

            int lowNum = num[low];
            int highNum = num[high];
            while (low < high && num[++low] == lowNum) ;
            while (low < high && num[--high] == highNum) ;
          }
          else if (num[i] + num[j] + num[low] + num[high] < target)
            ++low;
          else
            --high;
        }
      }
    }

    return result;
  }
};

int main()
{
  int size;
  scanf("%d", &size);
  std::vector<int> num;
  for (int i = 0; i < size; ++i)
  {
    int temp;
    scanf("%d", &temp);
    num.push_back(temp);
  }

  int target;
  scanf("%d", &target);

  Solution s;
  std::vector<std::vector<int> > result = s.fourSum(num, target);

  for (auto iter = result.begin(); iter != result.end(); ++iter)
  {
    for (auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
      printf("%d ", *iter2);
    puts("");
  }

  return 0;
}

