#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template<class Type>
class Node
{
public:
  Type val;
  Node<Type>* next;

public:
  Node();
  Node(const Type& value);
  Node(const Node<Type>& node);
  virtual ~Node();
};

// !!!
// template header must add, Node<Type> must add
template<class Type>
Node<Type>::Node()
  : val()
{
  std::cout << "Construct default node" << std::endl;
  next = NULL;
}

template<class Type>
Node<Type>::Node(const Type& value)
  : val(value)
{
  std::cout << "Construct value node" << std::endl;
  next = NULL;
}

template<class Type>
Node<Type>::Node(const Node<Type>& node)
  : val(node.val)
{
  std::cout << "Copy construct node" << std::endl;
  next = node.next;
}

template<class Type>
Node<Type>::~Node()
{
  std::cout << "Destroy node" << std::endl;
}

#endif

