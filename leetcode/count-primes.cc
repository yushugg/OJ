#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n < 2) return 0;
    int count = 0;
    vector<bool> nums(n + 1, true);
    nums[0] = nums[1] = false;
    int cur = 2;
    while (cur <= n) {
      int c = 2, nn = cur * c;
      while (nn <= n) {
        nums[nn] = false;
        nn = cur * ++c;
      }
      bool find = false;
      for (int i = cur + 1; i <= n; ++i) 
        if (nums[i]) { cur = i; find = true; break; }
      if (!find) break;
    }

    for (int i = 0; i < n; ++i) if (nums[i]) ++count;
    
    return count;
  }
};

int main() {
  int n;
  scanf("%d", &n);

  Solution s;
  printf("%d\n", s.countPrimes(n));

  return 0;
}

