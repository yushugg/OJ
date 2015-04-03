#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
  int rob(std::vector<int> &num) {
    if (num.size() == 0)
      return 0;
    if (num.size() <= 2)
      return *std::max_element(num.begin(), num.end());

    std::vector<int> money(num.size(), 0);
    money[0] = num[0];
    money[1] = num[1];
    for (int i = 2; i < num.size(); ++i)
    {
      if (i > 2)
        money[i] = std::max(money[i - 2] + num[i], money[i - 3] + num[i]);
      else
        money[i] = money[i - 2] + num[i];
    }

    return std::max(money[num.size() - 1], money[num.size() - 2]);
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

  Solution s;
  printf("%d\n", s.rob(num));

  return 0;
}

