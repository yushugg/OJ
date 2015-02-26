#include <cstdio>
#include <cstring>


class Solution {
public:
  int numTrees(int n) {
    int* G = new int[n + 1];
    memset(G, 0, (n + 1) * sizeof(int));
    G[0] = G[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
      for (int j = 1; j <= i; ++j)
      {
        G[i] += G[j - 1] * G[i - j];
      }
    }

    int result = G[n];

    delete[] G;

    return result;
  }
};


int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);

  Solution solution;
  int result = solution.numTrees(n);
  printf("%d\n", result);

  return 0;
}

