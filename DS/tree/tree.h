#ifndef TREE_H_
#define TREE_H_

#include "node.h"

template<class Type>
class Tree
{
private:
  Node<Type>* root;

public:
  Tree();
  Tree(const Tree<Type>& tree);
  virtual ~Tree();

private:
  Node<Type>* copyNode(Node<Type>* destNode, const Node<Type>* srcNode);
  void freeNode(Node<Type>* node);

  void preOrder(Node<Type>* node);
  void inOrder(Node<Type>* node);
  void postOrder(Node<Type>* node);

  Node<Type>* findNode(Node<Type>* node, const Type& val);
  Node<Type>* insertNode(Node<Type>* node, const Type& val);
  Node<Type>* findMin(Node<Type>* node);
  Node<Type>* delNode(Node<Type>* node, const Type& val);

public:
  bool empty();
  bool find(const Type& val);
  void insert(const Type& val);
  void del(const Type& val);
  void preOrderTraversal();
  void inOrderTraversal();
  void postOrderTraversal();

public:
  Tree<Type>& operator=(const Tree<Type>& tree);
};

template<class Type>
Tree<Type>::Tree()
{
  root = NULL;
  std::cout << "Construct an empty tree" << std::endl;
}

template<class Type>
Tree<Type>::Tree(const Tree<Type>& tree)
{
  root = copyNode(root, tree.root);
  std::cout << "Copy construct a tree" << std::endl;
}

template<class Type>
Tree<Type>::~Tree()
{
  freeNode(root);

  std::cout << "Destroy tree!" << std::endl;
}

template<class Type>
Node<Type>* Tree<Type>::copyNode(Node<Type>* destNode, const Node<Type>* srcNode)
{
  if (srcNode)
  {
    destNode = new Node<Type>(srcNode->value);
    destNode->left = copyNode(destNode->left, srcNode->left);
    destNode->right = copyNode(destNode->right, srcNode->right);

    return destNode;
  }

  return NULL;
}

template<class Type>
void Tree<Type>::freeNode(Node<Type>* node)
{
  if (node)
  {
    freeNode(node->left);
    freeNode(node->right);
    delete node;
  }
}

template<class Type>
bool Tree<Type>::empty()
{
  return root == NULL;
}

template<class Type>
Node<Type>* Tree<Type>::findNode(Node<Type>* node, const Type& val)
{
  if (!node)
    return NULL;

  if (node->value > val)
    return findNode(node->left, val);
  else if (node->value < val)
    return findNode(node->right, val);
  else
    return node;
}

template<class Type>
bool Tree<Type>::find(const Type& val)
{
  return findNode(root, val) != NULL;
}

template<class Type>
Node<Type>* Tree<Type>::insertNode(Node<Type>* node, const Type& val)
{
  if (!node)
  {
    node = new Node<Type>(val);
    return node;
  }
  else if (node->value < val)
  {
    node->right = insertNode(node->right, val);
  }
  else if (node->value > val)
  {
    node->left = insertNode(node->left, val);
  }

  return node;
}

template<class Type>
void Tree<Type>::insert(const Type& val)
{
  root = insertNode(root, val);
}

template<class Type>
Node<Type>* Tree<Type>::findMin(Node<Type>* node)
{
  if (!node)
    return NULL;
  else if (!node->left)
    return node;
  else
    return findMin(node->left);
}

template<class Type>
Node<Type>* Tree<Type>::delNode(Node<Type>* node, const Type& val)
{
  if (!node)
    return NULL;
  else if (val < node->value)
    node->left = delNode(node->left, val);
  else if (val > node->value)
    node->right = delNode(node->right, val);
  // Two children
  else if (node->left && node->right)
  {
    Node<Type>* temp = findMin(node->right);
    node->value = temp->value;
    node->right = delNode(node->right, temp->value);
  }
  // One or zero children
  else
  {
    Node<Type>* temp = node;
    if (!node->left)
      node = node->right;
    else if (!node->right)
      node = node->left;
    delete temp;
  }

  return node;
}

template<class Type>
void Tree<Type>::del(const Type& val)
{
  delNode(root, val);
}

template<class Type>
void Tree<Type>::preOrder(Node<Type>* node)
{
  if (node)
  {
    std::cout << node->value << " " << std::endl;
    preOrder(node->left);
    preOrder(node->right);
  }
}

template<class Type>
void Tree<Type>::inOrder(Node<Type>* node)
{
  if (node)
  {
    inOrder(node->left);
    std::cout << node->value << " " << std::endl;
    inOrder(node->right);
  }
}

template<class Type>
void Tree<Type>::postOrder(Node<Type>* node)
{
  if (node)
  {
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value << " " << std::endl;
  }
}

template<class Type>
void Tree<Type>::preOrderTraversal()
{
  std::cout << "Pre-Order: " << std::endl;
  preOrder(root);
}

template<class Type>
void Tree<Type>::inOrderTraversal()
{
  std::cout << "In-Order: " << std::endl;
  inOrder(root);
}

template<class Type>
void Tree<Type>::postOrderTraversal()
{
  std::cout << "Post-Order: " << std::endl;
  postOrder(root);
}

template<class Type>
Tree<Type>& Tree<Type>::operator=(const Tree<Type>& tree)
{
  std::cout << "Assign a tree" << std::endl;
  if (this == &tree)
    return *this;

  // Clear
  freeNode(root);
  copyNode(root, tree.root);
  return *this;
}

#endif

