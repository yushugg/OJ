#include <iostream>
#include <cstdio>

#include "sorting.h"

int main()
{
  freopen("in.txt", "r", stdin);

  Sorting s;
  int arr[100];
  size_t num;

  std::cout << "Input the sequence number(limit 100 numbers): " << std::endl;
  std::cin >> num;

  std::cout << "Input the sequence: " << std::endl;
  for (size_t i = 0; i < num; ++i)
    std::cin >> arr[i];
  s.show(arr, num);

  //s.insertionSort(arr, num);
  //s.selectionSort(arr, num);
  //s.bubbleSort(arr, num);
  //s.shellSort(arr, num);
  //s.heapSort(arr, num);
  //s.mergeSort(arr, num);
  s.quickSort(arr, num);

  return 0;
}

