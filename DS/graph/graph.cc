#include <iostream>

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

  std::cout << "Construct a graph, vertices number is: " << numOfVertices << std::endl;
}

Graph::Graph(const Graph& g)
{
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

  std::cout << "Destroy a graph, vertices number is: " << numOfVertices << std::endl;

  numOfVertices = 0;
}

void Graph::setEdge(size_t vertex1, size_t vertex2, int weight)
{
  vertices[vertex1][vertex2] = weight;
  verticesList[vertex1].push_back(vertex2);
  ++verticesList[vertex1].front();
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

  std::cout << "Assign a graph, vertices number is: " << numOfVertices << std::endl;

  return *this;
}

