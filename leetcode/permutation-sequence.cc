#include <string>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    string result;
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i)
      visited[i] = false;

    int every = 1;
    int ii;
    for (ii = 0; ii < n - 1; ++ii)
      every *= ii + 1;

    --k;
    for (int i = 0; i < n; ++i)
    {
      int num = k / every;
      int count = 0;
      for (int j = 0; j < n; ++j)
      {
        if (!visited[j])
        {
          if (count == num)
          {
            result.push_back('1' + j);
            visited[j] = true;
            k = k % every;
            if (ii)
              every /= ii;
            --ii;
            break;
          }
          ++count;
        }
      }
    }

    return result;
  }
};

int main()
{
  int n, k;
  cin >> n >> k;

  Solution s;
  cout << s.getPermutation(n, k) << endl;

  return 0;
}

