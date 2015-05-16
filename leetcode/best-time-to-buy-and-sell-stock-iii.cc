#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int size = prices.size();
    vector<int> forward(size, 0), backward(size, 0);
    int lowest = prices[0];
    for (int i = 1; i < size; ++i) {
      forward[i] = max(forward[i - 1], prices[i] - lowest);
      lowest = min(lowest, prices[i]);
    }
    int highest = prices[size - 1];
    for (int i = size - 2; i >= 0; --i) {
      backward[i] = max(backward[i + 1], highest - prices[i]);
      highest = max(highest, prices[i]);
    }

    int maxPro = 0;
    for (int i = 0; i < size; ++i) {
      maxPro = max(maxPro, forward[i] + backward[i]);
    }
    return maxPro;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> prices;
  while (size--) {
    int price;
    scanf("%d", &price);
    prices.push_back(price);
  }

  Solution solution;
  printf("%d\n", solution.maxProfit(prices));

  return 0;
}

