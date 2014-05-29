#include "fraction.h"

int main()
{
  Fraction f1, f2;
  Fraction f3(12, -8);
  std::cin >> f1 >> f2;
  Fraction f4 = f2;

  std::cout << "====================================" << std::endl;
  std::cout << "These are outputs: " << std::endl;
  std::cout << "f1: " << f1 << std::endl;
  std::cout << "f2: " << f2 << std::endl;
  f3.reduction();
  std::cout << "f3: " << f3 << std::endl;
  f4.reciprocal();
  std::cout << "f4: " << f4 << std::endl;

  std::cout << "f1+f2: " << f1+f2 << std::endl;
  std::cout << "f1-f2: " << f1-f2 << std::endl;
  std::cout << "f1*f2: " << f1*f2 << std::endl;
  std::cout << "f1/f2: " << f1/f2 << std::endl;

  std::cout << "f1==f2: " << (f1==f2) << std::endl;
  std::cout << "f1!=f2: " << (f1!=f2) << std::endl;
  std::cout << "f1>f2: " << (f1>f2) << std::endl;
  std::cout << "f1<f2: " << (f1<f2) << std::endl;
  std::cout << "f1>=f2: " << (f1>=f2) << std::endl;
  std::cout << "f1<=f2: " << (f1<=f2) << std::endl;

  std::cout << "-f1: " << -f1 << std::endl;
  std::cout << "!f1: " << !f1 << std::endl;

  std::cout << "++f1: " << ++f1 << std::endl;
  std::cout << "--f1: " << --f1 << std::endl;
  std::cout << "f1++: " << f1++ << std::endl;
  std::cout << "f1--: " << f1-- << std::endl;

  f2 = f1;
  std::cout << "f2: " << f1 << std::endl;
  return 0;
}

