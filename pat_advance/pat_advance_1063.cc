#include <cstdio>
#include <set>

int countSim(std::set<int> set1, std::set<int> set2)
{
  int count = 0;
  std::set<int>::iterator iter1 = set1.begin();
  std::set<int>::iterator iter2 = set2.begin();
  while (iter1 != set1.end() && iter2 != set2.end())
  {
    if (*iter1 < *iter2)
      ++iter1;
    else if (*iter1 > *iter2)
      ++iter2;
    else
    {
      ++count;
      ++iter1;
      ++iter2;
    }
  }

  return count;
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);
  std::set<int> sets[50];

  for (int i = 0; i < N; ++i)
  {
    int M;
    scanf("%d", &M);
    for (int j = 0; j < M; ++j)
    {
      int num;
      scanf("%d", &num);
      if (sets[i].find(num) == sets[i].end())
        sets[i].insert(num);
    }
  }

  int K;
  scanf("%d", &K);
  for (int i = 0; i < K; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);

    int nc = countSim(sets[a-1], sets[b-1]);
    int nt = sets[a-1].size() + sets[b-1].size() - nc;
    printf("%.1lf%%\n", 1.0*nc/nt*100);
  }

  return 0;
}

