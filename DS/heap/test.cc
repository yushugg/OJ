#include <iostream>

#include "heap.h"

int main()
{
  Heap heap;
  std::cout << heap.empty() << std::endl;
  std::cout << heap.deleteMin() << std::endl;

  int arrs[] = {150, 80, 40, 30, 10, 70, 110, 100, 20, 90, 60, 50, 120, 140, 130};
  heap.build(arrs, 15);
  heap.show();

  std::cout << heap.deleteMin() << std::endl;
  std::cout << heap.deleteMin() << std::endl;
  std::cout << heap.deleteMin() << std::endl;

  Heap heap2 = heap;
  heap2.insert(105);
  heap2.show();

  heap2 = heap;
  heap2.show();

  return 0;
}

