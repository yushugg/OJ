#include <iostream>

#include "list.h"

int main()
{
  List<int> l;
  l.show();
  std::cout << "empty: " << l.empty() << std::endl;

  l.push_back(1);
  l.push_front(2);
  l.push_front(3);
  l.push_back(4);
  l.show();

  l.pop_front();
  l.show();
  l.pop_back();
  l.show();

  std::cout << "front: " << l.front() << std::endl;
  std::cout << "back: " << l.back() << std::endl;

  List<int> ll = l;
  l.clear();
  l.show();
  ll.show();

  ll.pop_front();
  ll.show();
  ll.pop_back();
  ll.show();
  ll.pop_front();
  ll.show();
  ll.pop_back();
  ll.show();

  ll.push_front(5);
  ll.show();

  ll = l;
  ll.show();

  return 0;
}

