#ifndef ZERODIVISIONEXCEPTION_H_
#define ZERODIVISIONEXCEPTION_H_

#include <iostream>

class ZeroDivisionException
{
public:
  ZeroDivisionException();
  virtual ~ZeroDivisionException();

public:
  void printException();
};

#endif

