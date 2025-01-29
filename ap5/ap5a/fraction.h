#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction {
    private:
    long numerator;
    long denominator;

    public:

    Fraction(long numerator = 0, long denominator = 1);
    Fraction(int numerator); //Conversor int para fração
    ~Fraction();

    Fraction operator-()const;
    Fraction& operator++();
    Fraction& operator--();
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    friend Fraction operator+(const Fraction& lf, const Fraction& rf);
    friend Fraction operator-(const Fraction& lf, const Fraction& rf);
    friend Fraction operator*(const Fraction& lf, const Fraction& rf);
    friend Fraction operator/(const Fraction& lf, const Fraction& rf);
    
    operator double() const; //De fração para double

    friend istream& operator>>(istream& in, Fraction& f1);
    friend ostream& operator<<(ostream& out, const Fraction& f1);

    void fractionToDouble();

};

#endif