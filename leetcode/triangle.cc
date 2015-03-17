class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.empty())
      return 0;

    for (int i = 1; i < triangle.size(); ++i)
    {
      for (int j = 0; j <= i; ++j)
      {
        if (j != 0 && j != i)
        {
          int min = triangle[i - 1][j - 1] <= triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j];
          triangle[i][j] += min;
        }
        else if (j == 0)
          triangle[i][j] += triangle[i - 1][j];
        else
          triangle[i][j] += triangle[i - 1][j - 1];
      }
    }

    int min = triangle.back().front();
    for (auto iter = triangle.back().begin(); iter != triangle.back().end(); ++iter)
      if (min > *iter)
        min = *iter;

    return min;
  }
};
