#include <cstdio>
#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int> > &matrix) {
    int row0, col0;
    row0 = col0 = 1;
    for (int i = 0; i < matrix.size(); ++i)
    {
      if (!matrix[i][0])
      {
        col0 = 0;
        break;
      }
    }

    for (int i = 0; i < matrix[0].size(); ++i)
    {
      if (!matrix[0][i])
      {
        row0 = 0;
        break;
      }
    }

    // Count and set result to row 0 or col 0
    for (int i = 1; i < matrix.size(); ++i)
    {
      for (int j = 0; j < matrix[i].size(); ++j)
      {
        if (!matrix[i][j])
        {
          matrix[i][0] = 0;
          break;
        }
      }
    }

    for (int i = 1; i < matrix[0].size(); ++i)
    {
      for (int j = 0; j < matrix.size(); ++j)
      {
        if (!matrix[j][i])
        {
          matrix[0][i] = 0;
          break;
        }
      }
    }

    // Set zeros
    for (int i = 1; i < matrix.size(); ++i)
    {
      if (!matrix[i][0])
      {
        for (int j = 1; j < matrix[i].size(); ++j)
          matrix[i][j] = 0;
      }
    }

    for (int i = 1; i < matrix[0].size(); ++i)
    {
      if (!matrix[0][i])
      {
        for (int j = 1; j < matrix.size(); ++j)
          matrix[j][i] = 0;
      }
    }

    if (!row0)
    {
      for (int i = 0; i < matrix[0].size(); ++i)
        matrix[0][i] = 0;
    }

    if (!col0)
    {
      for (int i = 0; i < matrix.size(); ++i)
        matrix[i][0] = 0;
    }
  }
};

int main(int argc, char* argv[])
{
  int row, col;
  scanf("%d%d", &row, &col);

  std::vector<std::vector<int> > matrix;
  for (int i = 0; i < row; ++i)
  {
    std::vector<int> line;
    for (int j = 0; j < col; ++j)
    {
      int num;
      scanf("%d", &num);
      line.push_back(num);
    }
    matrix.push_back(line);
  }

  Solution s;
  s.setZeroes(matrix);

  // Output result
  for (auto iter1 = matrix.begin(); iter1 != matrix.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
    {
      printf("%d ", *iter2);
    }
    putchar('\n');
  }

  return 0;
}

