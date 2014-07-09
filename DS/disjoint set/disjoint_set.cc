#include <iostream>

#include "disjoint_set.h"

DisjointSet::DisjointSet()
{
  size = 0;
  set = new int[size+1];
  set[0] = -1;

  std::cout << "Construct an empty DisjointSet." << std::endl;
}

DisjointSet::DisjointSet(int length)
{
  size = length;
  set = new int[size+1];
  set[0] = -1;
  for (int i = 1; i <= size; ++i)
    set[i] = -1;

  std::cout << "Construct a length: " << length << " DisjointSet." << std::endl;
}

DisjointSet::DisjointSet(const DisjointSet& disjSet)
{
  size = disjSet.size;
  set = new int[size+1];
  for (int i = 0; i <= size; ++i)
    set[i] = disjSet.set[i];

  std::cout << "Copy construct a length: " << size << " DisjointSet." << std::endl;
}

DisjointSet::~DisjointSet()
{
  std::cout << "Destroy a length: " << size << " DisjointSet." << std::endl;

  size = 0;
  delete[] set;
}

void DisjointSet::sUnion(int root1, int root2)
{
  if (set[root1] < set[root2])
    set[root2] = root1;
  else
  {
    // Union by height
    if (set[root1] == set[root2])
      --set[root2];
    set[root1] = root2;
  }
}

void DisjointSet::setUnion(int root1, int root2)
{
  sUnion(find(root1), find(root2));
}

int DisjointSet::find(int x)
{
  if (set[x] < 0)
    return x;
  else
    // Path compression
    return set[x] = find(set[x]);
}

void DisjointSet::show()
{
  for (int i = 1; i <= size; ++i)
    std::cout << set[i] << " ";
  std::cout << std::endl;
}

DisjointSet& DisjointSet::operator=(const DisjointSet& disjSet)
{
  std::cout << "Assign a disjoint set." << std::endl;
  if (this == &disjSet)
    return *this;

  delete[] set;
  size = disjSet.size;
  set = new int[size+1];
  for (int i = 0; i <= size; ++i)
    set[i] = disjSet.set[i];

  return *this;
}

