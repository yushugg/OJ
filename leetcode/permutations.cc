#include <cstdio>
#include <vector>

class Solution {
public:
  void generateNext(std::vector<std::vector<int> >& permutes, std::vector<int> p, int next, const std::vector<int>& num, std::vector<bool> visited, int count) {
    p.push_back(num[next]);
    ++count;
    visited[next] = true;

    if (count == num.size())
    {
      permutes.push_back(p);
      return ;
    }
    
    for (int i = 0; i < num.size(); ++i)
    {
      if (!visited[i])
        generateNext(permutes, p, i, num, visited, count);
    }
  }

  std::vector<std::vector<int> > permute(std::vector<int> &num) {
    std::vector<bool> visited;
    for (int i = 0; i < num.size(); ++i)
      visited.push_back(false);

    std::vector<std::vector<int> > permutes;
    for (int i = 0; i < num.size(); ++i)
    {
      std::vector<int> p;
      generateNext(permutes, p, i, num, visited, 0);
    }

    return permutes;
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  std::vector<int> num;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    num.push_back(temp);
  }

  Solution s;
  std::vector<std::vector<int> > results;
  results = s.permute(num);

  for (auto iter = results.begin(); iter != results.end(); ++iter)
  {
    for (auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
      printf("%d ", *iter2);

    putchar('\n');
  }

  return 0;
}

