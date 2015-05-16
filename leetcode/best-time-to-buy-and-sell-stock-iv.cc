#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    if (k > prices.size() / 2) {
      int sum = 0;
      for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) sum += prices[i] - prices[i - 1];
      }
      return sum;
    }

    vector<vector<int> > dp(k + 1, vector<int>(prices.size() + 1, 0));
    for (int i = 1; i <= k; ++i) {
      int t = dp[i - 1][0] - prices[0];
      for (int j = 1; j <= prices.size(); ++j) {
        dp[i][j] = max(dp[i][j - 1], t + prices[j - 1]);
        if (j < prices.size()) t = max(t, dp[i - 1][j] - prices[j]);
      }
    }
    return dp[k][prices.size()];
  }
};

int main() {
  int k, size;
  scanf("%d%d", &k, &size);
  vector<int> prices;
  while (size--) {
    int price;
    scanf("%d", &price);
    prices.push_back(price);
  }

  Solution solution;
  printf("%d\n", solution.maxProfit(k, prices));

  return 0;
}

