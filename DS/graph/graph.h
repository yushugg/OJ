#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>

class Graph
{
private:
  size_t numOfVertices;
  int** vertices;
  std::list<int>* verticesList;
  int* indegrees;
  bool* visited;

public:
  Graph(size_t num);
  Graph(const Graph& g);
  virtual ~Graph();

public:
  void setEdge(size_t vertex1, size_t vertex2, int weight = 1);
  void showMatrix();
  void showList();
  void showIndegrees();
  void showVisited();

public:
  void topologicalSort();
  void DFS(size_t vertex);
  void BFS(size_t vertex);

public:
  Graph& operator=(const Graph& g);
};

#endif

