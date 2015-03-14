#include <vector>
#include <algorithm>
#include <cstdio>

class Solution {
public:
  void generateNext(std::vector<std::vector<int> >& sets, std::vector<int> currentSet, const std::vector<int>& S, int idx, int count, int total) {
    if (currentSet.empty() || currentSet.back() < S[idx])
    {
      ++count;
      currentSet.push_back(S[idx]);
    }

    if (count == total)
    {
      sets.push_back(currentSet);
      return ;
    }

    int lastNum = currentSet.back();
    for (int i = 0; i < S.size(); ++i)
    {
      if (S[i] > lastNum)
        generateNext(sets, currentSet, S, i, count, total);
    }
  }

  std::vector<std::vector<int> > subsets(std::vector<int> &S) {
    // Sort
    std::sort(S.begin(), S.end());
    
    std::vector<std::vector<int> > sets;
    std::vector<int> zeroSet;
    sets.push_back(zeroSet);
    for (int i = 1; i <= S.size(); ++i)
    {
      std::vector<int> set;
      for (int j = 0; j < S.size(); ++j)
      {
        if (i + j <= S.size())
          generateNext(sets, set, S, j, 0, i);
      }
    }

    return sets;
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
  std::vector<std::vector<int> > result = s.subsets(S);
  for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1)
  {
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
      printf("%d ", *iter2);
    putchar('\n');
  }

  return 0;
}

