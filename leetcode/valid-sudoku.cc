#include <cstdio>
#include <cstring>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char> > &board) {
    int numOfRows = board.size();
    int numOfColumns = board[0].size();

    int* validation = new int[numOfRows];

    // Every row
    for (int i = 0; i < numOfRows; ++i)
    {
      memset(validation, 0, numOfRows * sizeof(int));
      for (int j = 0; j < numOfColumns; ++j)
      {
        if (board[i][j] != '.')
        {
          if (++validation[board[i][j] - '1'] > 1)
            return false;
        }
      }
    }

    // Every column
    for (int i = 0; i < numOfColumns; ++i)
    {
      memset(validation, 0, numOfRows * sizeof(int));
      for (int j = 0; j < numOfRows; ++j)
      {
        if (board[j][i] != '.')
        {
          if (++validation[board[j][i] - '1'] > 1)
            return false;
        }
      }
    }

    // 9 blocks
    for (int row = 0; row < 3; ++row)
    {
      for (int col = 0; col < 3; ++col)
      {
        memset(validation, 0, numOfRows * sizeof(int));
        for (int i = 0; i < 3; ++i)
        {
          for (int j = 0; j < 3; ++j)
          {
            if (board[i + row * 3][j + col * 3] != '.')
            {
              if (++validation[board[i + row * 3][j + col * 3] - '1'] > 1)
                return false;
            }
          }
        }
      }
    }

    delete[] validation;

    return true;
  }
};

int main(int argc, char* argv[])
{
  std::vector<std::vector<char> > board;
  for (int i = 0; i < 9; ++i)
  {
    std::vector<char> temp;
    for (int j = 0; j < 9; ++j)
    {
      char c;
      scanf("%c", &c);
      temp.push_back(c);
    }
    board.push_back(temp);
  }

  for (auto iteri = board.begin(); iteri != board.end(); ++iteri)
  {
    printf("new line: ");
    for (auto iterj = iteri->begin(); iterj != iteri->end(); ++iterj)
    {
      printf("%c", *iterj);
    }
    putchar('\n');
  }

  Solution s;
  printf("Valid: %d\n", s.isValidSudoku(board));

  return 0;
}

