#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

class DisjointSet
{
private:
  int size;
  int* set;

public:
  DisjointSet();
  DisjointSet(int length);
  DisjointSet(const DisjointSet& disjSet);
  virtual ~DisjointSet();

private:
  void sUnion(int root1, int root2);

public:
  void setUnion(int root1, int root2);
  int find(int x);
  void show();

public:
  DisjointSet& operator=(const DisjointSet& disjSet);
};

#endif

