#include <vector>
#include <cstdio>

class Solution {
public:
  enum Direction {left, right, up, down};

  std::vector<std::vector<int> > generateMatrix(int n) {
    int row = 0;
    int col = 0;
    int num = n;
    Direction direction = right;
    int count = 0;

    std::vector<std::vector<int> > result;
    for (int i = 0; i < n; ++i)
    {
      std::vector<int> line;
      for (int j = 0; j < n; ++j)
        line.push_back(0);
      result.push_back(line);
    }

    while (count < n * n)
    {
      switch (direction)
      {
      case left:
        result[row][col] = count + 1;
        ++count;
        --col;
        if (col == n - num - 1)
        {
          ++col;
          --count;
          direction = up;
        }
        break;
      case right:
        result[row][col] = count + 1;
        ++count;
        ++col;
        if (col == num)
        {
          --col;
          --count;
          direction = down;
        }
        break;
      case up:
        result[row][col] = count + 1;
        ++count;
        --row;
        if (row == n - num)
        {
          ++row;
          --count;
          direction = right;
          --num;
        }
        break;
      case down:
        result[row][col] = count + 1;
        ++count;
        ++row;
        if (row == num)
        {
          --row;
          --count;
          direction = left;
        }
        break;
      }
    }

    return result;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);

  Solution s;
  std::vector<std::vector<int> > result = s.generateMatrix(n);
  for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
    {
      printf("%d ", *iter2);
    }
    putchar('\n');
  }

  return 0;
}
