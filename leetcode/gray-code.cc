#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool gray(int currentVal, int n, vector<int>& result, bool* table, int& count) {
    if (table[currentVal])
    {
      return false;
    }
    else
    {
      table[currentVal] = true;
      ++count;
      result.push_back(currentVal);

      bool done = count == int(pow(2, n));
      if (done)
      {
        bool ok = false;
        int mask = 1;
        for (int i = 0; i < n; ++i)
        {
          if ((result.back() ^ mask) == 0)
            ok = true;
          mask <<= 1;
        }

        return ok;
      }
    }

    int mask = 1;
    for (int i = 0; i < n; ++i)
    {
      if (gray(currentVal ^ mask, n, result, table, count))
        return true;
      mask <<= 1;
    }

    table[currentVal] = false;
    --count;

    return false;
  }

  vector<int> grayCode(int n) {
    vector<int> result;
    bool* table = new bool[int(pow(2, n))];
    for (int i = 0; i < int(pow(2, n)); ++i)
      table[i] = false;

    result.push_back(0);
    table[0] = true;
    int count = 1;
    gray(1, n, result, table, count);

    delete[] table;

    if (!n)
      result.pop_back();

    return result;
  }

  vector<int> grayCodeAnother(int n) {
    vector<int> result;
    for (int i = 0; i < 1<<n; ++i)
      result.push_back(i ^ i>>1);

    return result;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);

  Solution s;
  vector<int> grays = s.grayCodeAnother(n);

  for (auto iter = grays.begin(); iter != grays.end(); ++iter)
    printf("%d ", *iter);
  putchar('\n');

  return 0;
}

