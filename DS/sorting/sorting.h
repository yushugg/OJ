#ifndef SORTING_H_
#define SORTING_H_

class Sorting
{
public:
  // Simple sorts
  void insertionSort(int arr[], size_t num);
  void selectionSort(int arr[], size_t num);

  // Efficient sorts
  void mergeSort(int arr[], size_t num);
  void heapSort(int arr[], size_t num);
  void quickSort(int arr[], size_t num);

  // Bubble sorts
  void bubbleSort(int arr[], size_t num);
  void shellSort(int arr[], size_t num);

  // Distribution sorts
  void bucketSort(int arr[], size_t num);
  void radixSort(int arr[], size_t num);

  // Show
  void show(int arr[], size_t num);

private:
  void MSort(int arr[], int tempArr[], size_t left, size_t right);
  void merge(int arr[], int tempArr[], size_t left, size_t rCenter, size_t right);

  void QSort(int arr[], size_t left, size_t right);
  int mid(int arr[], size_t left, size_t right);
};

#endif

