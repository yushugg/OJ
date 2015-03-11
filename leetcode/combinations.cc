#include <vector>
#include <cstdio>

class Solution {
public:
  void generate(std::vector<std::vector<int> >& result, std::vector<int> com, int next, int n, int count, int k) {
    if (count < k)
    {
      if (com.empty() || next > com.back())
      {
        com.push_back(next);
        ++count;
        if (com.size() == k)
        {
          result.push_back(com);
          return ;
        }
      }

      for (int i = com.back() + 1; i <= n; ++i)
        generate(result, com, i, n, count, k);
    }
  }

  std::vector<std::vector<int> > combine(int n, int k) {
    std::vector<std::vector<int> > result;
    std::vector<int> combination;
    for (int i = 1; i <= n; ++i)
      generate(result, combination, i, n, 0, k);

    return result;
  }
};

int main(int argc, char* argv[])
{
  int n, k;
  scanf("%d%d", &n, &k);

  std::vector<std::vector<int> > result;
  Solution s;
  result = s.combine(n, k);
  for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
      printf("%d ", *iter2);
    putchar('\n');
  }

  return 0;
}

