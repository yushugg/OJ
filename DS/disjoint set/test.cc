#include <iostream>

#include "disjoint_set.h"

int main()
{
  DisjointSet disjSet(10);
  disjSet.show();

  disjSet.setUnion(5, 6);
  disjSet.show();

  disjSet.setUnion(7, 8);
  disjSet.show();

  disjSet.setUnion(5, 7);
  disjSet.show();

  std::cout << disjSet.find(5) << std::endl;

  DisjointSet disjSet2 = disjSet;
  disjSet2.show();

  disjSet2.setUnion(1, 7);
  disjSet2.show();

  disjSet2 = disjSet;
  disjSet2.show();

  return 0;
}

