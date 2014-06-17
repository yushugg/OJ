#include <iostream>

#include "tree.h"

int main()
{
  Tree<int> tree;
  std::cout << "tree empty: " << tree.empty() << std::endl;
  tree.del(3);
  tree.insert(3);
  tree.insert(1);
  tree.insert(5);
  tree.insert(4);
  tree.insert(6);
  tree.insert(7);
  tree.insert(2);

  tree.preOrderTraversal();
  tree.inOrderTraversal();
  tree.postOrderTraversal();

  std::cout << "Find 5: " << tree.find(5) << std::endl;
  std::cout << "Find 9: " << tree.find(9) << std::endl;

  tree.del(5);
  tree.preOrderTraversal();

  tree.del(1);
  tree.inOrderTraversal();

  tree.insert(0);
  tree.postOrderTraversal();

  tree.del(3);
  tree.inOrderTraversal();

  Tree<int> tree2 = tree;
  tree2.preOrderTraversal();
  tree2.del(4);
  tree2 = tree;
  tree2.postOrderTraversal();
}

