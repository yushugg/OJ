#include <iostream>

#include "graph.h"

int main()
{
  //std::cout << "Input the number of vertices: ";
  size_t numOfVertices = 7;
  //std::cin >> numOfVertices;

  Graph g(numOfVertices);
  g.setEdge(0, 2);
  g.setEdge(0, 1);
  g.setEdge(0, 3);
  g.setEdge(1, 3);
  g.setEdge(3, 2);
  g.setEdge(1, 4);
  g.setEdge(4, 3);
  g.setEdge(3, 5);
  g.setEdge(2, 5);
  g.setEdge(3, 6);
  g.setEdge(4, 6);
  g.setEdge(6, 5);

  g.showMatrix();
  g.showList();

  Graph g2 = g;
  g2.setEdge(1, 6);
  g2.showMatrix();
  g2.showList();

  g2 = g;
  g2.showMatrix();
  g2.showList();

  return 0;
}

