#include <iostream>

#include "list.h"

template<class Type>
List<Type>::List()
{
  length = 0;

  header = new Node<Type>;
  header->next = NULL;

  tail = header;

  std::cout << "Construct an empty list" << std::endl;
}

template<class Type>
List<Type>::List(const List<Type>& list)
{
  length = 0;

  header = new Node<Type>;
  header->next = NULL;

  tail = header;

  Node<Type>* p = list.header->next;
  while (p != NULL)
  {
    push_back(p->val);
    p = p->next;
  }

  std::cout << "Copy construct a list" << std::endl;
}

template<class Type>
List<Type>::~List()
{
  length = 0;
  // delete nodes
  Node<Type>* p = header;
  do
  {
    header = header->next;
    delete p;
    p = header;
  }while(p != NULL);

  std::cout << "Destroy a list" << std::endl;
}

template<class Type>
bool List<Type>::empty()
{
  return header->next == NULL;
}

template<class Type>
size_t List<Type>::size()
{
  return length;
}

template<class Type>
Type List<Type>::front()
{
  return header->next->val;
}

template<class Type>
Type List<Type>::back()
{
  return tail->val;
}

template<class Type>
void List<Type>::push_back(const Type& value)
{
  Node<Type>* node = new Node<Type>(value);
  tail->next = node;
  tail = node;

  ++length;
}

template<class Type>
void List<Type>::push_front(const Type& value)
{
  Node<Type>* node = new Node<Type>(value);
  node->next = header->next;
  header->next = node;

  ++length;
}

template<class Type>
void List<Type>::pop_back()
{
  if (!length)
    return;

  Node<Type>* p = header;
  while (p->next != tail)
  {
    p = p->next;
  }

  delete tail;
  tail = p;

  --length;
}

template<class Type>
void List<Type>::pop_front()
{
  if (!length)
    return;

  Node<Type>* p = header->next->next;
  delete header->next;
  header->next = p;

  --length;
}

template<class Type>
void List<Type>::clear()
{
  while (length)
    pop_front();
}

template<class Type>
void List<Type>::sort()
{
}

template<class Type>
void List<Type>::show()
{
  std::cout << "list size is: " << length << std::endl;
  std::cout << "list element is: " << std::endl;
  Node<Type>* p = header->next;
  while (p != NULL)
  {
    std::cout << "\t" << p->val << std::endl;
    p = p->next;
  }
}

template<class Type>
List<Type>& List<Type>::operator=(const List<Type>& list)
{
  if (this == &list)
    return *this;

  clear();
  Node<Type>* p = list.header->next;
  while (p != NULL)
  {
    push_back(p->val);
    p = p->next;
  }

  std::cout << "Assign a list" << std::endl;

  return *this;
}

