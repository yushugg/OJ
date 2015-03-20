#include <vector>
#include <cstdio>

class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    std::vector<int> diff;
    for (int i = 0; i < gas.size(); ++i)
      diff.push_back(gas[i] - cost[i]);

    // Find min postion
    int min = 0;
    for (int i = 0; i < diff[i]; ++i)
      if (diff[min] > diff[i])
        min = i;

    int start = min - 1 >= 0 ? min - 1 : diff.size() - 1;
    int end = start;
    int sum = 0;

    do {
      ++end;
      if (end > diff.size() - 1)
        end = 0;
      sum += diff[end];

      while (sum < 0 && start != end)
      {
        sum += diff[start];
        --start;
        if (start < 0)
          start = diff.size() - 1;
      }

    } while (start != end);

    if (sum < 0)
      return -1;
    else
      return start + 1 > diff.size() - 1 ? 0 : start + 1;
  }
};

int main(int argc, char* argv[])
{
  int size;
  scanf("%d", &size);

  std::vector<int> gas, cost;
  for (int i = 0; i < size; ++i)
  {
    int temp;
    scanf("%d", &temp);
    gas.push_back(temp);
  }
  for (int i = 0; i < size; ++i)
  {
    int temp;
    scanf("%d", &temp);
    cost.push_back(temp);
  }

  Solution s;
  printf("%d\n", s.canCompleteCircuit(gas, cost));

  return 0;
}


