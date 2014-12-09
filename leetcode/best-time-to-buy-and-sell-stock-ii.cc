#include <cstdio>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices)
  {
    int sum = 0;

    for (size_t i = 1; i < prices.size(); ++i)
    {
      if (prices[i] > prices[i - 1])
        sum += prices[i] - prices[i - 1];
    }

    return sum;
  }
};

int main()
{
  freopen("in.txt", "r", stdin);

  std::vector<int> prices;

  int price;
  while (scanf("%d", &price) != EOF)
    prices.push_back(price);

  Solution solution;
  printf("%d\n", solution.maxProfit(prices));

  return 0;
}

