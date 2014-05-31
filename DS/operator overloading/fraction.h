#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

class Fraction
{
private:
  int numerator;
  int denominator;
  bool flag;

public:
  Fraction();
  Fraction(int num, int deno);
  Fraction(const Fraction& f);
  virtual ~Fraction();

private:
  int gcd() const;

public:
  void reduction();
  void reciprocal();

public:
  // arithmetric
  friend Fraction operator+(const Fraction& f1, const Fraction& f2);
  friend Fraction operator-(const Fraction& f1, const Fraction& f2);
  friend Fraction operator*(const Fraction& f1, const Fraction& f2);
  friend Fraction operator/(const Fraction& f1, const Fraction& f2);

  // io
  friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
  friend std::istream& operator>>(std::istream& in, Fraction& f);

  // comparison
  friend bool operator==(const Fraction& f1, const Fraction& f2);
  friend bool operator!=(const Fraction& f1, const Fraction& f2);
  friend bool operator>(const Fraction& f1, const Fraction& f2);
  friend bool operator<(const Fraction& f1, const Fraction& f2);
  friend bool operator>=(const Fraction& f1, const Fraction& f2);
  friend bool operator<=(const Fraction& f1, const Fraction& f2);

  // unary
  Fraction operator-();
  bool operator!();

  // increment and decrement
  Fraction& operator++();
  Fraction& operator--();
  Fraction operator++(int);
  Fraction operator--(int);

  // assignment
  Fraction& operator=(const Fraction& f);
};

#endif

