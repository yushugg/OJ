#ifndef NODE_H_
#define NODE_H_

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

#endif

