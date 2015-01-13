#include <vector>

class Solution {
public:
  std::vector<std::vector<int> > generate(int numRows) {
    std::vector<std::vector<int> > pascal;

    for (int i = 0; i < numRows; ++i)
    {
      std::vector<int> item;
      for (int j = 0; j <= i; ++j)
      {
        if (j == 0 || j == i)
          item.push_back(1);
        else
          item.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
      }
      pascal.push_back(item);
    }

    return pascal;
  }
};
