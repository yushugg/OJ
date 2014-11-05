#include <cstdio>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>

int paths[100];
std::vector<std::stack<int> > resultPath;

void dfs(int root, std::list<int>* adjacents, int adjacentSize)
{
  for (auto iter = adjacents[root].begin(); iter != adjacents[root].end(); ++iter)
  {
    paths[*iter] = root;
    dfs(*iter, adjacents, adjacentSize);
  }
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N, M, objectWeight;
  scanf("%d%d%d", &N, &M, &objectWeight);

  // Adjacent list
  std::list<int>* adjacents = new std::list<int>[N];

  // Weight array
  int* weightArray = new int[N];
  for (int i = 0; i < N; ++i)
    scanf("%d", &weightArray[i]);

  // None leaf nodes
  for (int i = 0; i < M; ++i)
  {
    int index, numberOfChildren;
    scanf("%d%d", &index, &numberOfChildren);
    for (int j = 0; j < numberOfChildren; ++j)
    {
      int item;
      scanf("%d", &item);
      adjacents[index].push_back(item);
    }
  }

  dfs(0, adjacents, N);

  // Find suitable path
  for (int i = 0; i < N; ++i)
  {
    if (adjacents[i].empty())
    {
      int start = i;
      int sum = weightArray[0];
      while (start)
      {
        sum += weightArray[start];
        start = paths[start];
      }

      if (sum == objectWeight)
      {
        std::stack<int> result;
        start = i;
        while (start)
        {
          result.push(weightArray[start]);
          start = paths[start];
        }
        result.push(weightArray[0]);
        resultPath.push_back(result);
      }
    }
  }

  std::sort(resultPath.begin(), resultPath.end(), [](std::stack<int> s1, std::stack<int> s2) -> bool{
    while (!s1.empty() && !s2.empty())
    {
      if (s1.top() != s2.top())
        return s1.top() > s2.top();
      else
      {
        s1.pop();
        s2.pop();
      }
    }
    if (!s1.empty())
      return true;
    if (!s2.empty())
      return false;
    // Strict weak ordering, compare(x, x) must return false for any x
    return false;
  });

  for (auto iter = resultPath.begin(); iter != resultPath.end(); ++iter)
  {
    while (iter->size() > 1)
    {
      printf("%d ", iter->top());
      iter->pop();
    }
    printf("%d\n", iter->top());
    iter->pop();
  }
  
  delete[] weightArray;
  delete[] adjacents;

  return 0;
}

