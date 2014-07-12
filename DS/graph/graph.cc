#include <iostream>
#include <queue>

#include "graph.h"

Graph::Graph(size_t num)
{
  numOfVertices = num;

  vertices = new int*[numOfVertices];
  for (size_t i = 0; i != numOfVertices; ++i)
    vertices[i] = new int[numOfVertices];

  // Set no edge between vertices
  for (size_t i = 0; i != numOfVertices; ++i)
    for (size_t j = 0; j != numOfVertices; ++j)
      vertices[i][j] = 0;

  // Adjacency list
  verticesList = new std::list<int>[numOfVertices];
  // Add header for each list, containing the number of vertices
  for (size_t i = 0; i != numOfVertices; ++i)
    verticesList[i].push_back(0);

  // Indegrees
  indegrees = new int[numOfVertices];
  for (size_t i = 0; i != numOfVertices; ++i)
    indegrees[i] = 0;

  std::cout << "Construct a graph, vertices number is: " << numOfVertices << std::endl;
}

Graph::Graph(const Graph& g)
{
  // Indegrees
  indegrees = new int[g.numOfVertices];
  for (size_t i = 0; i != g.numOfVertices; ++i)
    indegrees[i] = g.indegrees[i];

  // Allocate memory
  numOfVertices = g.numOfVertices;
  vertices = new int*[numOfVertices];
  for (size_t i = 0; i != numOfVertices; ++i)
    vertices[i] = new int[numOfVertices];

  // Assign
  for (size_t i = 0; i != numOfVertices; ++i)
    for (size_t j = 0; j != numOfVertices; ++j)
      vertices[i][j] = g.vertices[i][j];

  // Adjacency list
  verticesList = new std::list<int>[g.numOfVertices];
  for (size_t i = 0; i != numOfVertices; ++i)
  {
    for (std::list<int>::iterator iter = g.verticesList[i].begin(); iter != g.verticesList[i].end(); ++iter)
      verticesList[i].push_back(*iter);
  }

  std::cout << "Copy construct a graph, vertices number is: " << numOfVertices << std::endl;
}

Graph::~Graph()
{
  for (size_t i = 0; i != numOfVertices; ++i)
    delete[] vertices[i];
  delete[] vertices;

  // Adjacency list
  for (size_t i = 0; i != numOfVertices; ++i)
    verticesList[i].clear();
  delete[] verticesList;

  // Indegrees
  delete[] indegrees;

  std::cout << "Destroy a graph, vertices number is: " << numOfVertices << std::endl;

  numOfVertices = 0;
}

void Graph::setEdge(size_t vertex1, size_t vertex2, int weight)
{
  vertices[vertex1][vertex2] = weight;

  verticesList[vertex1].push_back(vertex2);
  ++verticesList[vertex1].front();

  ++indegrees[vertex2];
}

void Graph::showMatrix()
{
  for (size_t i = 0; i != numOfVertices; ++i)
  {
    for (size_t j = 0; j != numOfVertices; ++j)
    {
      std::cout << vertices[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Graph::showList()
{
  for (size_t i = 0; i != numOfVertices; ++i)
  {
    std::cout << i << ": ";
    for (std::list<int>::iterator iter = verticesList[i].begin(); iter != verticesList[i].end(); ++iter)
      std::cout << *iter << "->";
    std::cout << std::endl;
  }
}

void Graph::showIndegrees()
{
  std::cout << "Indegrees are: " << std::endl;
  for (size_t i = 0; i != numOfVertices; ++i)
    std::cout << i << ": " << indegrees[i] << std::endl;
}

void Graph::topologicalSort()
{
  // Copy indegrees
  int* in = new int[numOfVertices];
  for (size_t i = 0; i != numOfVertices; ++i)
    in[i] = indegrees[i];

  std::queue<size_t> q;
  for (size_t i = 0; i != numOfVertices; ++i)
  {
    if (!in[i])
      q.push(i);
  }

  size_t count = 0;
  while (!q.empty())
  {
    size_t top = q.front();
    std::cout << top << "-";
    q.pop();
    ++count;

    std::list<int>::iterator iter = verticesList[top].begin();
    for (++iter ; iter != verticesList[top].end(); ++iter)
    {
      if (--in[*iter] == 0)
        q.push(*iter);
    }
  }

  if (count != numOfVertices)
    std::cout << "The graph has a cycle." << std::endl;
  std::cout << std::endl;

  delete[] in;
}

Graph& Graph::operator=(const Graph& g)
{
  if (this == &g)
    return *this;

  // Clear
  for (size_t i = 0; i != numOfVertices; ++i)
    delete[] vertices[i];
  delete[] vertices;
  // Adjacency list
  for (size_t i = 0; i != numOfVertices; ++i)
    verticesList[i].clear();
  delete[] verticesList;
  // Indegrees
  delete[] indegrees;

  // Allocate memory
  numOfVertices = g.numOfVertices;
  vertices = new int*[numOfVertices];
  for (size_t i = 0; i != numOfVertices; ++i)
    vertices[i] = new int[numOfVertices];
  // Adjacency list
  verticesList = new std::list<int>[g.numOfVertices];
  // Indegrees
  indegrees = new int[g.numOfVertices];

  // Assign
  for (size_t i = 0; i != numOfVertices; ++i)
    for (size_t j = 0; j != numOfVertices; ++j)
      vertices[i][j] = g.vertices[i][j];
  // Adjacency list
  for (size_t i = 0; i != numOfVertices; ++i)
  {
    for (std::list<int>::iterator iter = g.verticesList[i].begin(); iter != g.verticesList[i].end(); ++iter)
      verticesList[i].push_back(*iter);
  }
  // Indegrees
  for (size_t i = 0; i != numOfVertices; ++i)
    indegrees[i] = g.indegrees[i];

  std::cout << "Assign a graph, vertices number is: " << numOfVertices << std::endl;

  return *this;
}

