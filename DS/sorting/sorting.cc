#include <iostream>
#include <algorithm>

#include "sorting.h"

void Sorting::insertionSort(int arr[], size_t num)
{
  std::cout << "Begin insertion sorting..." << std::endl;

  for (size_t i = 1; i < num; ++i)
  {
    int temp = arr[i];
    size_t j;
    for (j = i; j > 0; --j)
    {
      if (temp < arr[j-1])
        arr[j] = arr[j-1];
      else
        break;
    }

    arr[j] = temp;
  }

  std::cout << "Insertion sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::selectionSort(int arr[], size_t num)
{
  std::cout << "Begin selection sorting..." << std::endl;

  for (size_t i = 0; i < num; ++i)
  {
    size_t min = i;
    for (size_t j = i+1; j < num; ++j)
    {
      if (arr[j] < arr[min])
        min = j;
    }

    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
  
  std::cout << "Selection sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::MSort(int arr[], int tempArr[], size_t left, size_t right)
{
  if (left < right)
  {
    size_t center = (left + right) / 2;
    MSort(arr, tempArr, left, center);
    MSort(arr, tempArr, center+1, right);
    merge(arr, tempArr, left, center+1, right);
  }
}

void Sorting::merge(int arr[], int tempArr[], size_t left, size_t rCenter, size_t right)
{
  size_t leftEnd = rCenter - 1;
  size_t rightEnd = right;
  size_t lp = left;
  size_t rp = rCenter;
  size_t tp = left;

  while (lp <= leftEnd && rp <= rightEnd)
  {
    if (arr[lp] < arr[rp])
      tempArr[tp++] = arr[lp++];
    else
      tempArr[tp++] = arr[rp++];
  }

  while (lp <= leftEnd)
    tempArr[tp++] = arr[lp++];
  while (rp <= rightEnd)
    tempArr[tp++] = arr[rp++];

  // Copy back
  for (size_t i = left; i <= right; ++i)
    arr[i] = tempArr[i];
}

void Sorting::mergeSort(int arr[], size_t num)
{
  std::cout << "Begin merge sorting..." << std::endl;

  int* tempArr = new int[num];
  MSort(arr, tempArr, 0, num-1);
  delete[] tempArr;
  
  std::cout << "Merge sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::heapSort(int arr[], size_t num)
{
  std::cout << "Begin heap sorting..." << std::endl;

  // Move one step
  for (size_t i = num; i > 0; --i)
    arr[i] = arr[i-1];
  arr[0] = -999999;

  // Build heap
  for (size_t i = num / 2; i > 0; --i)
  {
    size_t j, child;
    int temp = arr[i];
    for (j = i; j * 2 <= num; j = child)
    {
      child = j * 2;
      if (child < num && arr[child+1] > arr[child])
        ++child;

      if (arr[child] > temp)
        arr[j] = arr[child];
      else
        break;
    }
    arr[j] = temp;
  }
  std::cout << "Heap builded." << std::endl;
  show(arr, num+1);

  // Delete max
  for (size_t i = 1; i < num; ++i)
  {
    int max = arr[1];
    int last = arr[num-i+1];
    size_t j, child;
    for (j = 1; j * 2 <= num-i; j = child)
    {
      child = j * 2;
      if (child < num-i && arr[child+1] > arr[child])
        ++child;

      if (arr[child] > last)
        arr[j] = arr[child];
      else
        break;
    }
    arr[j] = last;
    arr[num-i+1] = max;
    show(arr, num+1);
  }

  // Move back
  for (size_t i = 0; i < num; ++i)
    arr[i] = arr[i+1];
  
  std::cout << "Heap sorting completed." << std::endl;
  show(arr, num);
}

int Sorting::mid(int arr[], size_t left, size_t right)
{
  size_t center = (left + right) / 2;
  
  if (arr[left] > arr[center])
    std::swap(arr[left], arr[center]);
  if (arr[left] > arr[right])
    std::swap(arr[left], arr[right]);
  if (arr[center] > arr[right])
    std::swap(arr[center], arr[right]);

  std::swap(arr[center], arr[right]);
  return arr[right];
}

void Sorting::QSort(int arr[], size_t left, size_t right)
{
  if (right - left + 1 > 3)
  {
    int pivot = mid(arr, left, right);
    size_t i = left;
    size_t j = right - 1;

    while (true)
    {
      while (arr[i] < pivot) ++i;
      while (arr[j] > pivot) --j;
      if (i < j)
        std::swap(arr[i], arr[j]);
      else
        break;
    }
    std::swap(arr[i], arr[right]);

    QSort(arr, left, i - 1);
    QSort(arr, i + 1, right);
  }
  else
    insertionSort(arr + left, right - left + 1);
}

void Sorting::quickSort(int arr[], size_t num)
{
  std::cout << "Begin quick sorting..." << std::endl;

  QSort(arr, 0, num-1);
  
  std::cout << "Quick sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::bubbleSort(int arr[], size_t num)
{
  std::cout << "Begin bubble sorting..." << std::endl;

  for (size_t i = 0; i < num-1; ++i)
  {
    for (size_t j = 0; j < num-i-1; ++j)
    {
      if (arr[j+1] < arr[j])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  std::cout << "Bubble sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::shellSort(int arr[], size_t num)
{
  std::cout << "Begin shell sorting..." << std::endl;

  for (size_t increment = num / 2; increment > 0; increment /= 2)
  {
    for (size_t i = increment; i < num; ++i)
    {
      int temp = arr[i];
      size_t j;
      for (j = i; j >= increment; j -= increment)
      {
        if (temp < arr[j-increment])
          arr[j] = arr[j-increment];
        else
          break;
      }
      arr[j] = temp;
    }
  }
  
  std::cout << "Shell sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::bucketSort(int arr[], size_t num)
{
  std::cout << "Begin bucket sorting..." << std::endl;
  
  std::cout << "Bucket sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::radixSort(int arr[], size_t num)
{
  std::cout << "Begin radix sorting..." << std::endl;
  
  std::cout << "Radix sorting completed." << std::endl;
  show(arr, num);
}

void Sorting::show(int arr[], size_t num)
{
  for (size_t i = 0; i < num; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  std::cout << std::endl;
}
