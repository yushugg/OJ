#include "fraction.h"

Fraction::Fraction()
{
  numerator = 1;
  denominator = 1;
  std::cout << "Construct fraction: " << numerator << "/" << denominator << std::endl;
}

Fraction::Fraction(int num, int deno)
{
  numerator = num;
  denominator = deno;
  std::cout << "Construct fraction: " << numerator << "/" << denominator << std::endl;
}

Fraction::Fraction(const Fraction& f)
{
  numerator = f.numerator;
  denominator = f.denominator;
  std::cout << "Copy construct fraction: " << numerator << "/" << denominator << std::endl;
}

virtual Fraction::~Fraction()
{
  std::cout << "destroy fraction: " << numerator << "/" << denominator << std::endl;
}

int Fraction::gcd() const
{
  int max = numerator >= 0 ? numerator : -numerator;
  int min = denominator >= 0 ? denominator : -denominator;

  if (max < min)
  {
    int temp = max;
    max = min;
    min = temp;
  }

  while (min)
  {
    int rem = max % min;
    max = min;
    min = rem;
  }

  return max;
}

void Fraction::reduction()
{
  int gcdNum = gcd();
  numerator /= gcdNum;
  denominator /= gcdNum;
}

void Fraction::reciprocal()
{
  int temp = numerator;
  numerator = denominator;
  denominator = temp;
}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
  return Fraction(f1.numerator*f2.denominator+f2.numerator*f1.denominator, f1.denominator*f2.denominator).reduction();
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
  return Fraction(f1.numerator*f2.denominator-f2.numerator*f1.denominator, f1.denominator*f2.denominator).reduction();
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
  return Fraction(f1.numerator*f2.numerator, f1.denominator*f2.denominator).reduction();
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
  Fraction temp(f2);
  return f1*f2.reciprocal();
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
  out << f.numerator << "/" << f.denominator;
  return out;
}

std::istream& operator>>(std::istream& in, const Fraction& f)
{
  std::cout << "Input a fraction, two numbers" << std::endl;
  in >> f.numerator >> f.denominator;
  return in;
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
  Fraction temp1(f1), temp2(f2);
  temp1.reduction();
  temp2.reduction();
  
  return temp1.numerator * temp2.denominator == temp1.denominator * temp2.numerator;
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
  Fraction temp1(f1), temp2(f2);
  temp1.reduction();
  temp2.reduction();
  
  return temp1.numerator * temp2.denominator != temp1.denominator * temp2.numerator;
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
  Fraction result = f1 - f2;

  return result.numerator*result.denominator > 0;
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
  return f2 > f1;
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
  Fraction result = f1 - f2;

  return result.numerator*result.denominator >= 0;
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
  return f2 >= f1;
}

Fraction Fraction::operator-()
{
  return Fraction(-numerator, denominator);
}

bool Fraction::operator!()
{
  return *this != Fraction(0, 1);
}

Fraction& Fraction::operator++()
{
  *this = *this+Fraction(1, 1);
  return *this;
}

Fraction& Fraction::operator--()
{
  *this = *this-Fraction(1, 1);
  return *this;
}

Fraction Fraction::operator++(int)
{
  Fraction temp(*this);
  *this = *this+Fraction(1, 1);
  return temp;
}

Fraction Fraction::operator--(int)
{
  Fraction temp(*this);
  *this = *this-Fraction(1, 1);
  return temp;
}

Fraction& Fraction::operator=(const Fraction& f)
{
  if (this == &f)
    return *this;

  numerator = f.numerator;
  denominator = f.denominator;

  return *this;
}
