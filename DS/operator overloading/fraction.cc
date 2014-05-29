#include "fraction.h"

Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}

Fraction::Fraction(int num, int deno)
{
  numerator = num;
  denominator = deno;
}

Fraction::Fraction(const Fraction& f)
{
  numerator = f.numerator;
  denominator = f.denominator;
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

Fraction& Fraction::reduction()
{
  int result = gcd();
}
