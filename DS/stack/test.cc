#include <string>

#include "stack.h"

#define TESTINT

int main()
{
#ifdef TESTINT
  Stack<int> stack;
  std::cout << "empty: " << stack.empty() << std::endl;
  std::cout << "size: " << stack.size() << std::endl;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  stack.push(1);
  stack.push(2);
  stack.push(3);
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;
  Stack<int> stack2 = stack;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  stack.clear();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "capacity: " << stack.capa() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  std::cout << "size: " << stack2.size() << std::endl;
  std::cout << "capacity: " << stack2.capa() << std::endl;
  std::cout << "top: " << stack2.top() << std::endl;
  
  stack = stack2;
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "capacity: " << stack.capa() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  for (int i = 0; i < 16; ++i)
  {
    stack.push(i);
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << "capacity: " << stack.capa() << std::endl;
    std::cout << "top: " << stack.top() << std::endl;
  }

  for (int i = 0; i < 16; ++i)
  {
    stack.pop();
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << "capacity: " << stack.capa() << std::endl;
    std::cout << "top: " << stack.top() << std::endl;
  }
#else
  Stack<std::string> stack;
  std::cout << "empty: " << stack.empty() << std::endl;
  std::cout << "size: " << stack.size() << std::endl;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  stack.push(std::string("1"));
  stack.push(std::string("2"));
  stack.push(std::string("3"));
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;
  Stack<std::string> stack2 = stack;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  stack.clear();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "capacity: " << stack.capa() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  std::cout << "size: " << stack2.size() << std::endl;
  std::cout << "capacity: " << stack2.capa() << std::endl;
  std::cout << "top: " << stack2.top() << std::endl;
  
  stack = stack2;
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "capacity: " << stack.capa() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;

  for (int i = 0; i < 16; ++i)
  {
    stack.push("iii");
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << "capacity: " << stack.capa() << std::endl;
    std::cout << "top: " << stack.top() << std::endl;
  }

  for (int i = 0; i < 16; ++i)
  {
    stack.pop();
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << "capacity: " << stack.capa() << std::endl;
    std::cout << "top: " << stack.top() << std::endl;
  }
#endif

  return 0;
}

