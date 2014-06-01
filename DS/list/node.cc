#include <iostream>

#include "node.h"

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

