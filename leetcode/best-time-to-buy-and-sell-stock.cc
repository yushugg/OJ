#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int maxPro = 0;
    int minPrev;
    if (!prices.empty())
      minPrev = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      int min = minPrev > prices[i-1] ? prices[i-1] : minPrev;
      int profit = prices[i] - min;
      if (profit > maxPro)
        maxPro = profit;
      minPrev = min;
    }

    return maxPro;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  std::vector<int> prices;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    prices.push_back(temp);
  }

  Solution s;
  printf("%d\n", s.maxProfit(prices));

  return 0;
}
