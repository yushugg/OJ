#include <cstdio>
#include <list>
#include <queue>
#include <algorithm>

const int MaxDist = 1E8;

struct Table
{
  int minDist;
  bool visited;
};

struct NeighDist
{
  int neigh;
  int dist;
};

struct HeapNode
{
  int index;
  int dist;

  bool operator<(const HeapNode& hn) const
  {
    return dist > hn.dist;
  }
};

std::list<NeighDist> neighList[1020];
Table table[1020];

void Dijkstra(int src, int tableSize)
{
  table[src].minDist = 0;

  while (true)
  {
    bool flag = true;
    int min;
    for (int i = 1; i <= tableSize; ++i)
    {
      if (!table[i].visited)
      {
        min = i;
        flag = false;
        break;
      }
    }
    if (flag)
      break;
    // Find min
    for (int i = 1; i <= tableSize; ++i)
    {
      if (!table[i].visited && table[i].minDist < table[min].minDist)
        min = i;
    }

    table[min].visited = true;

    for (std::list<NeighDist>::iterator iter = neighList[min].begin(); iter != neighList[min].end(); ++iter)
    {
      if (!table[iter->neigh].visited && table[min].minDist + iter->dist < table[iter->neigh].minDist)
      {
        table[iter->neigh].minDist = table[min].minDist + iter->dist;
      }
    }
  }
}

int readStr(char str[], int N)
{
  int res;
  if (str[0] != 'G')
    sscanf(str, "%d", &res);
  else
  {
    char temp[5];
    int i = 0;
    while (str[i] != '\0')
    {
      temp[i] = str[i+1];
      ++i;
    }
    int t;
    sscanf(temp, "%d", &t);
    res = N + t;
  }

  return res;
}

void initTable(Table table[], int tableSize)
{
  for (int i = 1; i <= tableSize; ++i)
  {
    table[i].minDist = MaxDist;
    table[i].visited = false;
  }
}

int main()
{
  freopen("in.txt", "r", stdin);

  // Read data
  int N, M, K, Ds;
  scanf("%d%d%d%d", &N, &M, &K, &Ds);

  for (int i = 0; i < K; ++i)
  {
    char first[5];
    char second[5];
    int dist;
    scanf("%s%s%d", first, second, &dist);

    int fir = readStr(first, N);
    int sec = readStr(second, N);

    NeighDist nd;
    nd.neigh = sec;
    nd.dist = dist;
    neighList[fir].push_back(nd);
    NeighDist nd2;
    nd2.neigh = fir;
    nd2.dist = dist;
    neighList[sec].push_back(nd2);
  }

  int minSum = MaxDist;
  int minD = -1;
  int maxIndex = 0;
  for (int i = N+1; i <= N+M; ++i)
  {
    initTable(table, N+M);

    Dijkstra(i, N+M);

    int sum = 0;
    int min = MaxDist;
    int max = 0;
    for (int j = 1; j <= N; ++j)
    {
      sum += table[j].minDist;
      if (min > table[j].minDist)
        min = table[j].minDist;
      if (max < table[j].minDist)
        max = table[j].minDist;
    }

    if (max <= Ds)
    {
      if (min > minD || (minD == min && sum < minSum))
      {
        minSum = sum;
        maxIndex = i;
        minD = min;
      }
    }
  }

  if (maxIndex)
    printf("G%d\n%.1lf %.1lf\n", maxIndex-N, minD * 1.0, 1.0 * minSum / N);
  else
    printf("No Solution\n");

  return 0;
}

