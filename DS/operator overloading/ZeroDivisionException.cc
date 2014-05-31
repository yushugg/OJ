#include "ZeroDivisionException.h"

ZeroDivisionException::ZeroDivisionException()
{
  std::cout << "Construct one ZeroDivisionException" << std::endl;
}

ZeroDivisionException::~ZeroDivisionException()
{
  std::cout << "Destroy ZeroDivisionException" << std::endl;
}

void ZeroDivisionException::printException() const
{
  std::cerr << "Zero Division Error!" << std::endl;
}
