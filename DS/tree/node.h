#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template<class Type>
class Node
{
public:
  Type value;
  Node<Type>* left;
  Node<Type>* right;

public:
  Node();
  Node(const Type& val);
  Node(const Node<Type>& node);
  virtual ~Node();

public:
  Node<Type>& operator=(const Node<Type>& node);
};

template<class Type>
Node<Type>::Node()
  : value()
{
  left = NULL;
  right = NULL;

  std::cout << "Construct a Node" << std::endl;
}

template<class Type>
Node<Type>::Node(const Type& val)
  : value(val)
{
  left = NULL;
  right = NULL;

  std::cout << "Construct a Node, containing value: " << value << std::endl;
}

template<class Type>
Node<Type>::Node(const Node<Type>& node)
  : value(node.value)
{
  left = node.left;
  right = node.right;

  std::cout << "Copy construct a Node, value: " << value << std::endl;
}

template<class Type>
Node<Type>::~Node()
{
  left = NULL;
  right = NULL;

  std::cout << "Destroy a Node" << std::endl;
}

template<class Type>
Node<Type>& Node<Type>::operator=(const Node<Type>& node)
{
  if (this == &node)
    return *this;

  value = node.value;
  left = node.left;
  right = node.right;

  std::cout << "Assign a Node, value: " << value << std::endl;

  return *this;
}

#endif

