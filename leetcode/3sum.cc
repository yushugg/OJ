#include <cstdio>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int> > threeSum(std::vector<int> &num) {
    std::sort(num.begin(), num.end());
    std::vector<std::vector<int> > result;
    for (int i = 0; i < num.size(); ++i)
    {
      if (i > 0 && num[i] == num[i - 1])
        continue;
      int low = i + 1;
      int high = num.size() - 1;
      while (low < high)
      {
        if (num[low] + num[high] + num[i] == 0)
        {
          std::vector<int> temp;
          temp.push_back(num[low]);
          temp.push_back(num[high]);
          temp.push_back(num[i]);
          std::sort(temp.begin(), temp.end());
          result.push_back(temp);

          int numLow = num[low];
          int numHigh = num[high];
          while (low < high && num[++low] == numLow);
          while (low < high && num[--high] == numHigh);
        }
        else if (num[low] + num[high] + num[i] > 0)
          --high;
        else
          ++low;
      }
    }

    return result;
  }
};

int main()
{
  int size;
  std::vector<int> num;
  scanf("%d", &size);
  for (int i = 0; i < size; ++i)
  {
    int temp;
    scanf("%d", &temp);
    num.push_back(temp);
  }

  Solution s;
  std::vector<std::vector<int> > result = s.threeSum(num);
  for (auto iter = result.begin(); iter != result.end(); ++iter)
  {
    for (auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
      printf("%d ", *iter2);
    puts("");
  }

  return 0;
}

