#ifndef LIST_H_
#define LIST_H_

#include "node.h"

template<class Type>
class List
{
private:
  size_t length;
  Node<Type>* header;
  Node<Type>* tail;

public:
  List();
  List(const List<Type>& list);
  virtual ~List();

public:
  bool empty();
  size_t size();
  Type front();
  Type back();
  void push_back(const Type& value);
  void push_front(const Type& value);
  void pop_back();
  void pop_front();
  void clear();
  void sort();
  void show();

public:
  List<Type>& operator=(const List<Type>& list);
};

#endif

