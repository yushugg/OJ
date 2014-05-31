#include "ZeroDivisionException.h"
#include "fraction.h"

int main()
{
  try
  {
    Fraction f1, f2;
    int a = 12, b = -8;
    Fraction f3(a, b);

    std::cin >> f1 >> f2;
    Fraction f4 = f2;

    for (int i = 0; i < 15; ++i)
      std::cout << "==";
    std::cout << std::endl;

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
  }
  catch (const ZeroDivisionException& zdexcept)
  {
    zdexcept.printException();
  }
  return 0;
}

