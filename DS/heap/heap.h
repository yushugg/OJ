#ifndef HEAP_H_
#define HEAP_H_

class Heap
{
private:
  size_t size;
  enum { Capacity = 100 };
  static const int Min = -1000000;
  int elements[Capacity];

public:
  Heap();
  Heap(const Heap& heap);
  virtual ~Heap();

public:
  bool empty();
  void insert(int val);
  int deleteMin();
  void build(int values[], int length);
  void show();

public:
  Heap& operator=(const Heap& heap);
};

#endif

