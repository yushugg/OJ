#include <vector>
#include <cstdio>
#include <algorithm>

class Solution {
public:
  void nextSubset(std::vector<std::vector<int> >& subsets, std::vector<int> set, const std::vector<int>& S, int start, int n)
  {
    if (set.size() < n)
    {
      for (int i = start; i < S.size(); ++i)
      {
        if (i == start || S[i] != S[i - 1])
        {
          set.push_back(S[i]);
          nextSubset(subsets, set, S, i + 1, n);
          // Backtracking
          set.pop_back();
        }
      }
    }
    else
      subsets.push_back(set);
  }

  std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &S) {
    std::sort(S.begin(), S.end());
    std::vector<std::vector<int> > subsets;
    std::vector<int> set;
    for (int i = 0; i <= S.size(); ++i)
      nextSubset(subsets, set, S, 0, i);

    return subsets;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  std::vector<int> S;
  for (int i = 0; i < n; ++i)
  {
    int num;
    scanf("%d", &num);
    S.push_back(num);
  }

  Solution s;
  std::vector<std::vector<int> > subsets = s.subsetsWithDup(S);
  for (auto iter1= subsets.begin(); iter1 != subsets.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
      printf("%d ", *iter2);
    putchar('\n');
  }

  return 0;
}

