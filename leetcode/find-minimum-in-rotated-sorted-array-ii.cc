#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &num) {
    int low = 0, high = num.size() - 1, mid;
    while (low < high && num[low] >= num[high]) {
      mid = low + (high - low) / 2;
      if (num[mid] > num[low]) low = mid + 1;
      else if (num[mid] < num[low]) high = mid;
      else ++low;
    }

    return num[low];
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> num;
  for (int i = 0; i < size; ++i) { int temp; scanf("%d", &temp); num.push_back(temp); }

  Solution s;
  printf("%d\n", s.findMin(num));

  return 0;
}

