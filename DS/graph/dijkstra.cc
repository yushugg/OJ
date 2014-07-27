#include <iostream>
#include <cstdio>
#include <list>
#include <map>

const int VertexNumLimit = 100;
const int IntMaxLimit = 1E6;
const int IntMinLimit = -1E5;

struct Table
{
  bool known;
  int dist;
  int path;
};

std::map<int, Table> table;
std::map<int, std::list<std::pair<int, int> > > vertexList;

int findMin()
{
  int min = -1;
  int minDist = IntMaxLimit;
  for (std::map<int, Table>::iterator iter = table.begin(); iter != table.end(); ++iter)
  {
    if (!(iter->second).known && minDist > (iter->second).dist)
    {
      minDist = (iter->second).dist;
      min = iter->first;
    }
  }

  return min;
}

void Dijkstra()
{
  while (true)
  {
    int minVertex = findMin();
    if (minVertex < 0)
      break;
    table[minVertex].known = true;

    for (std::list<std::pair<int, int> >::iterator iter = vertexList[minVertex].begin(); iter != vertexList[minVertex].end(); ++iter)
    {
      if (!table[iter->first].known && iter->second + table[minVertex].dist < table[iter->first].dist)
      {
        table[iter->first].dist = iter->second + table[minVertex].dist;
        table[iter->first].path = minVertex;
      }
    }
  }
}

int main()
{
  freopen("in.txt", "r", stdin);
  // Read a graph
  int vertexNum;
  std::cin >> vertexNum;
  int edgeNum;
  std::cin >> edgeNum;
  int src;
  std::cin >> src;

  for (int i = 0; i < edgeNum; ++i)
  {
    int v1, v2, dist;
    std::cin >> v1 >> v2 >> dist;
    if (vertexList.find(v1) == vertexList.end())
    {
      std::list<std::pair<int, int> > temp;
      temp.push_back(std::make_pair(v2, dist));
      vertexList[v1] = temp;
    }
    else
      vertexList[v1].push_back(std::make_pair(v2, dist));
  }

  // Initialize the table
  for (int i = 0; i < vertexNum; ++i)
  {
    table[i+1].known = false;
    table[i+1].dist = IntMaxLimit;
    table[i+1].path = 0;
  }
  table[src].dist = 0;

  // Dijkstra
  Dijkstra();
  
  // Print table
  for (std::map<int, Table>::iterator iter = table.begin(); iter != table.end(); ++iter)
  {
    std::cout << iter->first << ": " << (iter->second).dist << " " << (iter->second).path << std::endl;
  }

  return 0;
}

