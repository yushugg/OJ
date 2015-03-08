#include <cstdio>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int> > &matrix) {
    size_t size = matrix.size();
    size_t n = size / 2;
    for (size_t i = 0; i != n; ++i)
    {
      for (size_t j = i; j != size - i - 1; ++j)
      {
        // matrix[i][j], matrix[j][size - i - 1], matrix[size - i - 1][size - j - 1], matrix[size - j - 1][i]
        int temp1 = matrix[i][j];
        matrix[i][j] = matrix[size - j - 1][i];
        int temp2 = matrix[j][size - i - 1];
        matrix[j][size - i - 1] = temp1;
        temp1 = matrix[size - i - 1][size - j - 1];
        matrix[size - i - 1][size - j - 1] = temp2;
        matrix[size - j - 1][i] = temp1;
      }
    }
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  std::vector<std::vector<int> > matrix;
  for (int i = 0; i < n; ++i)
  {
    std::vector<int> line;
    for (int j = 0; j < n; ++j)
    {
      int num;
      scanf("%d", &num);
      line.push_back(num);
    }
    matrix.push_back(line);
  }

  Solution s;
  s.rotate(matrix);

  for (auto iter1 = matrix.begin(); iter1 != matrix.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
      printf("%d ", *iter2);
    putchar('\n');
  }

  return 0;
}

