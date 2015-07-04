#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    int i = 0;
    while (i <= ratings.size()) {
      if (i == 0) { ++i; continue; }
      else if (i == ratings.size() || ratings[i] > ratings[i - 1]) {
        // forward
        int prev = i - 2;
        while (prev >= 0 && ratings[prev] >= ratings[prev + 1]) {
          if (ratings[prev] > ratings[prev + 1]) candies[prev] = max(candies[prev], candies[prev + 1] + 1);
          else candies[prev] = max(candies[prev], 1);
          --prev;
        }
        if (i == ratings.size()) break;
        // backward
        while (i < ratings.size() && ratings[i] >= ratings[i - 1]) {
          if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
          else candies[i] = 1;
          ++i;
        }
      } else ++i;
    }

    // Test
    for (int c : candies) cout << c << " ";
    cout << endl;

    int sum = 0;
    for (int c : candies) sum += c;
    return sum;
  }
};

int main() {
  int size;
  cin >> size;
  vector<int> ratings;
  while (size--) {
    int val;
    cin >> val;
    ratings.push_back(val);
  }

  Solution solution;
  cout << solution.candy(ratings) << endl;

  return 0;
}

