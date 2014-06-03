#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template<class Type>
class Stack
{
private:
  size_t length;
  size_t capacity;
  Type* data;
  size_t cur;

public:
  Stack();
  Stack(const Stack<Type>& stack);
  virtual ~Stack();

public:
  bool empty();
  size_t size();
  size_t capa();
  Type top();
  void push(const Type& value);
  void pop();
  void clear();

public:
  Stack<Type>& operator=(const Stack<Type>& stack);
};

template<class Type>
Stack<Type>::Stack()
{
  length = 0;
  capacity = 8;
  data = new Type[capacity];
  cur = -1;

  std::cout << "Construct empty stack" << std::endl;
}

template<class Type>
Stack<Type>::Stack(const Stack<Type>& stack)
{
  length = stack.length;
  capacity = stack.capacity;
  data = new Type[capacity];

  for (size_t i = 0; i < length; ++i)
  {
    *(data + i) = *(stack.data + i);
  }
  cur = stack.cur;

  std::cout << "Copy construct a stack" << std::endl;
}

template<class Type>
Stack<Type>::~Stack()
{
  capacity = 8;
  length = 0;
  cur = -1;

  delete[] data;

  std::cout << "Destroy a stack" << std::endl;
}

template<class Type>
bool Stack<Type>::empty()
{
  return length == 0;
}

template<class Type>
size_t Stack<Type>::size()
{
  return length;
}

template<class Type>
size_t Stack<Type>::capa()
{
  return capacity;
}

template<class Type>
Type Stack<Type>::top()
{
  if (length)
    return *(data + cur);
  else
  {
    Type t;
    return t;
  }
}

template<class Type>
void Stack<Type>::push(const Type& value)
{
  *(data + (++cur)) = value;
  ++length;

  if (length == capacity)
  {
    capacity *= 2;
    Type* temp = new Type[capacity];
    for (size_t i = 0; i < length; ++i)
    {
      *(temp + i) = *(data + i);
    }
    delete[] data;

    data = temp;
  }
}

template<class Type>
void Stack<Type>::pop()
{
  if (length)
  {
    if (length == capacity / 2 && capacity > 8)
    {
      capacity /= 2;
      Type* temp = new Type[capacity];
      for (size_t i = 0; i < capacity; ++i)
      {
        *(temp + i) = *(data + i);
      }
      delete[] data;
      data = temp;
    }
    --cur;
    --length;
  }
}

template<class Type>
void Stack<Type>::clear()
{
  length = 0;
  cur = -1;
  capacity = 8;
  delete[] data;

  data = new Type[capacity];
}

template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& stack)
{
  std::cout << "Assign a stack" << std::endl;
  if (this == &stack)
    return *this;

  length = stack.length;
  cur = stack.cur;
  capacity = stack.capacity;
  delete[] data;

  data = new Type[capacity];
  for (size_t i = 0; i < length; ++i)
  {
    *(data + i) = *(stack.data + i);
  }

  return *this;
}

#endif

