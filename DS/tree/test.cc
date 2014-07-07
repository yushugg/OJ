#include <iostream>

#include "tree.h"
#include "AVLTree.h"

//#define TREE

int main()
{
#ifdef TREE
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
#else
  AVLTree<int> avlTree;
  std::cout << "avlTree empty: " << avlTree.empty() << std::endl;
  avlTree.del(3);
  avlTree.insert(3);
  avlTree.insert(1);
  avlTree.insert(5);
  avlTree.insert(4);
  avlTree.insert(6);
  avlTree.insert(7);
  avlTree.insert(2);

  avlTree.preOrderTraversal();
  avlTree.inOrderTraversal();
  avlTree.postOrderTraversal();

  std::cout << "Find 5: " << avlTree.find(5) << std::endl;
  std::cout << "Find 9: " << avlTree.find(9) << std::endl;

  avlTree.del(5);
  avlTree.preOrderTraversal();

  avlTree.del(1);
  avlTree.inOrderTraversal();

  avlTree.insert(0);
  avlTree.postOrderTraversal();

  avlTree.del(3);
  avlTree.inOrderTraversal();

  AVLTree<int> avlTree2 = avlTree;
  avlTree2.preOrderTraversal();
  avlTree2.del(4);
  avlTree2 = avlTree;
  avlTree2.postOrderTraversal();
#endif
}

