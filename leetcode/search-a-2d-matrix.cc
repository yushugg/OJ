class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int low = 0;
    int high = matrix.size() - 1;
    int mid;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (matrix[mid][0] > target)
        high = mid - 1;
      else if (matrix[mid][0] < target)
        low = mid + 1;
      else
        return true;
    }

    // low is the insertion place
    int line;
    line = low - 1;
    if (line < 0)
      line = 0;

    int start = 0;
    int end = matrix[line].size() - 1;
    while (start <= end)
    {
      mid = (start + end) / 2;
      if (matrix[line][mid] > target)
        end = mid - 1;
      else if (matrix[line][mid] < target)
        start = mid + 1;
      else
        return true;
    }

    return false;
  }
};
