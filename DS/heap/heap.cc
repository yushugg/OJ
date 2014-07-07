#include <iostream>

#include "heap.h"

Heap::Heap()
{
  size = 0;
  elements[0] = Min;

  std::cout << "Initialize an empty heap." << std::endl;
}

Heap::~Heap()
{
  size = 0;
  elements[0] = Min;
  
  std::cout << "Destroy a heap." << std::endl;
}

Heap::Heap(const Heap& heap)
{
  size = heap.size;
  for (size_t i = 0; i <= size; ++i)
    elements[i] = heap.elements[i];

  std::cout << "Copy construct a heap." << std::endl;
}

bool Heap::empty()
{
  return size == 0;
}

void Heap::insert(int val)
{
  // Bubble up
  size_t i;
  for (i = ++size; elements[i / 2] > val; i /= 2)
    elements[i] = elements[i / 2];

  elements[i] = val;
}

int Heap::deleteMin()
{
  if (empty())
    return elements[0];

  int min = elements[1];
  int last = elements[size--];
  size_t child, i;

  for (i = 1; i * 2 <= size; i = child)
  {
    child = i * 2;
    if (child != size && elements[child+1] < elements[child])
      ++child;

    // Percolate down
    if (last > elements[child])
      elements[i] = elements[child];
    else
      break;
  }

  elements[i] = last;
  
  return min;
}

void Heap::build(int values[], int length)
{
  size = length;
  elements[0] = Min;

  for (size_t i = 1; i <= size; ++i)
  {
    elements[i] = values[i-1];
  }

  // Percolate down
  for (size_t i = size / 2; i >= 1; --i)
  {
    int downVal = elements[i];
    size_t j, child;

    for (j = i; j * 2 <= size; j = child)
    {
      child = j * 2;
      if (child != size && elements[child + 1] < elements[child])
        ++child;

      if (downVal > elements[child])
        elements[j] = elements[child];
      else
        break;
    }

    elements[j] = downVal;
  }
}

void Heap::show()
{
  std::cout << "Heap is: ";
  for (size_t i = 1; i <= size; ++i)
    std::cout << elements[i] << " ";

  std::cout <<std::endl;
}

Heap& Heap::operator=(const Heap& heap)
{
  if (this == &heap)
    return *this;

  size = heap.size;
  for (size_t i = 0; i <= size; ++i)
    elements[i] = heap.elements[i];

  return *this;
}

