#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "node.h"

#include <algorithm>

template<class Type>
class AVLTree
{
private:
  Node<Type>* root;

public:
  AVLTree();
  AVLTree(const AVLTree<Type>& tree);
  virtual ~AVLTree();

private:
  Node<Type>* findNode(Node<Type>* node, const Type& val);
  Node<Type>* findMin(Node<Type>* node);
  Node<Type>* findMax(Node<Type>* node);
  Node<Type>* insertNode(Node<Type>* node, const Type& val);
  Node<Type>* delNode(Node<Type>* node, const Type& val);

  Node<Type>* singleRotateWithLeft(Node<Type>* K2);
  Node<Type>* singleRotateWithRight(Node<Type>* K2);
  Node<Type>* doubleRotateWithLeft(Node<Type>* K3);
  Node<Type>* doubleRotateWithRight(Node<Type>* K3);

  void preOrder(Node<Type>* node);
  void inOrder(Node<Type>* node);
  void postOrder(Node<Type>* node);

  Node<Type>* copyNode(Node<Type>* destNode, const Node<Type>* srcNode);
  void freeNode(Node<Type>* node);

public:
  bool empty();
  bool find(const Type& val);
  void insert(const Type& val);
  void del(const Type& val);

public:
  void preOrderTraversal();
  void inOrderTraversal();
  void postOrderTraversal();

public:
  static int getHeight(Node<Type>* root);
  AVLTree<Type>& operator=(const AVLTree<Type>& tree);
};

template<class Type>
AVLTree<Type>::AVLTree()
{
  root = NULL;
  std::cout << "Construct an empty AVLTree" << std::endl;
}

template<class Type>
AVLTree<Type>::AVLTree(const AVLTree<Type>& tree)
{
  root = copyNode(root, tree.root);
  std::cout << "Copy construct a tree" << std::endl;
}

template<class Type>
AVLTree<Type>::~AVLTree()
{
  freeNode(root);
  std::cout << "Destroy tree!" << std::endl;
}

template<class Type>
Node<Type>* AVLTree<Type>::copyNode(Node<Type>* destNode, const Node<Type>* srcNode)
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
void AVLTree<Type>::freeNode(Node<Type>* node)
{
  if (node)
  {
    freeNode(node->left);
    freeNode(node->right);

    delete node;
    node = NULL;
  }
}

template<class Type>
bool AVLTree<Type>::empty()
{
  return root == NULL;
}

template<class Type>
Node<Type>* AVLTree<Type>::findNode(Node<Type>* node, const Type& val)
{
  if (!node)
    return NULL;

  if (val < node->value)
    return findNode(node->left, val);
  else if (val > node->value)
    return findNode(node->right, val);
  else
    return node;
}

template<class Type>
bool AVLTree<Type>::find(const Type& val)
{
  return findNode(root, val) != NULL;
}

template<class Type>
Node<Type>* AVLTree<Type>::singleRotateWithLeft(Node<Type>* K2)
{
  Node<Type>* K1;

  K1 = K2->left;
  K2->left = K1->right;
  K1->right = K2;

  K2->height = std::max(getHeight(K2->left), getHeight(K2->right)) + 1;
  K1->height = std::max(getHeight(K1->left), getHeight(K1->right)) + 1;

  return K1;
}

template<class Type>
Node<Type>* AVLTree<Type>::singleRotateWithRight(Node<Type>* K2)
{
  Node<Type>* K1;

  K1 = K2->right;
  K2->right = K1->left;
  K1->left = K2;

  K2->height = std::max(getHeight(K2->left), getHeight(K2->right)) +1;
  K1->height = std::max(getHeight(K1->left), getHeight(K1->right)) + 1;

  return K1;
}

template<class Type>
Node<Type>* AVLTree<Type>::doubleRotateWithLeft(Node<Type>* K3)
{
  K3->left = singleRotateWithRight(K3->left);

  return singleRotateWithLeft(K3);
}

template<class Type>
Node<Type>* AVLTree<Type>::doubleRotateWithRight(Node<Type>* K3)
{
  K3->right = singleRotateWithLeft(K3->right);

  return singleRotateWithRight(K3);
}

template<class Type>
Node<Type>* AVLTree<Type>::insertNode(Node<Type>* node, const Type& val)
{
  if (!node)
  {
    node = new Node<Type>(val);
  }
  else if (val < node->value)
  {
    node->left = insertNode(node->left, val);
    if (getHeight(node->left) - getHeight(node->right) == 2)
    {
      if (val < node->left->value)
        node = singleRotateWithLeft(node);
      else
        node = doubleRotateWithLeft(node);
    }
  }
  else if (val > node->value)
  {
    node->right = insertNode(node->right, val);
    if (getHeight(node->right) - getHeight(node->left) == 2)
    {
      if (val > node->right->value)
        node = singleRotateWithRight(node);
      else
        node = doubleRotateWithRight(node);
    }
  }

  node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

  return node;
}

template<class Type>
void AVLTree<Type>::insert(const Type& val)
{
  root = insertNode(root, val);
}

template<class Type>
Node<Type>* AVLTree<Type>::findMin(Node<Type>* node)
{
  if (!node)
    return NULL;
  else if (!node->left)
    return node;
  else
    return findMin(node->left);
}

template<class Type>
Node<Type>* AVLTree<Type>::findMax(Node<Type>* node)
{
  if (!node)
    return NULL;
  else if (!node->right)
    return node;
  else
    return findMax(node->right);
}

template<class Type>
Node<Type>* AVLTree<Type>::delNode(Node<Type>* node, const Type& val)
{
  if (!node)
    return NULL;
  else if (val < node->value)
  {
    node->left = delNode(node->left, val);
    if (getHeight(node->right) - getHeight(node->left) == 2)
    {
      if (getHeight(node->right->left) > getHeight(node->right->right))
        node = doubleRotateWithRight(node);
      else
        node = singleRotateWithRight(node);
    }
  }
  else if (val > node->value)
  {
    node->right = delNode(node->right, val);
    if (getHeight(node->left) - getHeight(node->right) == 2)
    {
      if (getHeight(node->left->right) > getHeight(node->left->left))
        node = doubleRotateWithLeft(node);
      else
        node = singleRotateWithLeft(node);
    }
  }

  else if (node->left && node->right)
  {
    Node<Type>* temp = findMin(node->right);
    node->value = temp->value;
    node->right = delNode(node->right, temp->value);
    if (getHeight(node->left) - getHeight(node->right) == 2)
    {
      if (getHeight(node->left->right) > getHeight(node->left->left))
        node = doubleRotateWithLeft(node);
      else
        node = singleRotateWithLeft(node);
    }
  }
  else
  {
    Node<Type>* temp = node;
    if (!node->left)
      node = node->right;
    else if (!node->right)
      node = node->left;

    delete temp;
  }

  if (node)
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

  return node;
}

template<class Type>
void AVLTree<Type>::del(const Type& val)
{
  root = delNode(root, val);
}

template<class Type>
void AVLTree<Type>::inOrder(Node<Type>* node)
{
  if (node)
  {
    inOrder(node->left);
    std::cout << node->value << " ";
    inOrder(node->right);
  }
}

template<class Type>
void AVLTree<Type>::preOrder(Node<Type>* node)
{
  if (node)
  {
    std::cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
  }
}

template<class Type>
void AVLTree<Type>::postOrder(Node<Type>* node)
{
  if (node)
  {
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value << " ";
  }
}

template<class Type>
void AVLTree<Type>::inOrderTraversal()
{
  std::cout << "In-Order: " << std::endl;
  inOrder(root);
  std::cout << std::endl;
}

template<class Type>
void AVLTree<Type>::preOrderTraversal()
{
  std::cout << "Pre-Order: " << std::endl;
  preOrder(root);
  std::cout << std::endl;
}

template<class Type>
void AVLTree<Type>::postOrderTraversal()
{
  std::cout << "Post-Order: " << std::endl;
  postOrder(root);
  std::cout << std::endl;
}

template<class Type>
AVLTree<Type>& AVLTree<Type>::operator=(const AVLTree<Type>& tree)
{
  std::cout << "Assign a tree" << std::endl;
  if (this == &tree)
    return *this;

  freeNode(root);
  root = copyNode(root, tree.root);
  return *this;
}

template<class Type>
int AVLTree<Type>::getHeight(Node<Type>* root)
{
  if (!root)
    return -1;
  else
    return root->height;
}

#endif

