#include <vector>
#include <algorithm>
#include <cstdio>

class Solution {
public:
  void nextPermutation(std::vector<int> &num) {
    for (int i = num.size() - 1; i >= 0; --i)
    {
      if (!i)
        std::sort(num.begin(), num.end());
      else if (num[i] > num[i - 1])
      {
        // Select min
        int min = i;
        for (int j = i; j < num.size() && num[j] > num[i - 1]; ++j)
          if (num[min] > num[j])
            min = j;
        // Swap
        std::swap(num[i - 1], num[min]);
        // Sort others
        std::sort(num.begin() + i, num.end());

        break;
      }
    }
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  std::vector<int> num;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    num.push_back(temp);
  }

  Solution s;
  s.nextPermutation(num);

  for (auto iter = num.begin(); iter != num.end(); ++iter)
    printf("%d ", *iter);
  putchar('\n');

  return 0;
}

