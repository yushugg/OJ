#include <iostream>
#include <string>

#include "list.h"

#define TESTINT

int main()
{
#ifdef TESTINT
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

#else
  List<std::string> strList;
  strList.show();
  std::cout << "empty: " << strList.empty() << std::endl;

  strList.push_back(std::string("Hello world"));
  strList.push_front(std::string("Wie geht's sie"));
  strList.show();

  strList.pop_front();
  strList.show();

  strList.clear();
  strList.show();
#endif

  return 0;
}

