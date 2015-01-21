#include <cstdio>
#include <vector>

class Solution {
public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> pascalRow;
    std::vector<int> lastRow;

    if (!rowIndex)
    {
      pascalRow.push_back(1);
      return pascalRow;
    }

    for (int k = 1; k <= rowIndex; ++k)
    {
      pascalRow.clear();
      pascalRow.push_back(1);
      for (int i = 1; i < k; ++i)
        pascalRow.push_back(lastRow[i - 1] + lastRow[i]);
      pascalRow.push_back(1);

      // Assign to lastRow
      lastRow.clear();
      lastRow.assign(pascalRow.begin(), pascalRow.end());
    }

    return pascalRow;
  }
};

int main(int argc, char* argv[])
{
  Solution s;
  std::vector<int> pascalRow = s.getRow(18);
  for (std::vector<int>::iterator iter = pascalRow.begin(); iter != pascalRow.end(); ++iter)
    printf("%d ", *iter);
  putchar('\n');

  return 0;
}

