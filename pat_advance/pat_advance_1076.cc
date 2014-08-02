#include <cstdio>
#include <list>
#include <queue>

std::list<int> nodes[1001];
bool visited[1001];
int levels[1001];

int main()
{
  freopen("in.txt", "r", stdin);
  // Read data
  int N, L;
  scanf("%d%d", &N, &L);

  for (int i = 0; i < N; ++i)
  {
    int userNum;
    scanf("%d", &userNum);
    for (int j = 0; j < userNum; ++j)
    {
      int parent;
      scanf("%d", &parent);
      nodes[parent].push_back(i+1);
    }
  }

  // Query
  int queryNum;
  scanf("%d", &queryNum);
  for (int i = 0; i < queryNum; ++i)
  {
    int query;
    scanf("%d", &query);
    for (int k = 0; k < 1001; ++k)
    {
      levels[k] = 0;
      visited[k] = false;
    }

    int forwardCnt = 0;

    std::queue<int> qq;
    qq.push(query);
    levels[query] = 0;
    visited[query] = true;
    
    while (!qq.empty())
    {
      int node = qq.front();
      qq.pop();
      if (levels[node] > L)
        break;
      if (levels[node])
        ++forwardCnt;
      for (std::list<int>::iterator iter = nodes[node].begin(); iter != nodes[node].end(); ++iter)
      {
        if (!visited[*iter])
        {
          // Put visit here, ensure one node put into the queue only once
          visited[*iter] = true;
          levels[*iter] = levels[node] + 1;
          qq.push(*iter);
        }
      }
    }
    //qq.clear();
    /*while (!qq.empty())
      qq.pop();*/

    printf("%d\n", forwardCnt);
  }

  return 0;
}

