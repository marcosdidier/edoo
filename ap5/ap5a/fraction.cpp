#include <iostream>
#include "fraction.h"

long gcd(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction::Fraction(long numerator, long denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0 ){
        cerr << "O denominador não pode ser 0" << endl;
        exit(EXIT_FAILURE);
    }
}

Fraction::Fraction(int num) : numerator(num), denominator(1){}


Fraction Fraction::operator-()const{
    return Fraction(-numerator, denominator);
}

Fraction& Fraction::operator++(){
    numerator++;
    return *this;
}

Fraction& Fraction::operator--(){
    numerator--;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& other){
    long mmc = denominator * other.denominator;
    long left = (mmc/denominator) * numerator;
    long right = (mmc/other.denominator) * other.numerator;
    numerator = left + right;
    denominator = mmc;

    long commonGCD = gcd(numerator, denominator);
    numerator /= commonGCD;
    denominator /= commonGCD;

    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
    long mmc = denominator * other.denominator;
    long left = (mmc/denominator) * numerator;
    long right = (mmc/other.denominator) * other.numerator;
    numerator = left - right;
    denominator = mmc;

    long commonGCD = gcd(numerator, denominator);
    numerator /= commonGCD;
    denominator /= commonGCD;

    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other){

    if (other.denominator == 0){
        cerr << "Não é possível ter denominador 0" << endl;
        exit(EXIT_FAILURE);
    }
    numerator *= other.numerator;
    denominator *= other.denominator;

    long commonGCD = gcd(numerator, denominator);
    numerator /= commonGCD;
    denominator /= commonGCD;

    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other){

    if (other.numerator == 0){
        cerr << "Não é possível ter denominador 0" << endl;
        exit(EXIT_FAILURE);
    }

    numerator *= other.denominator;
    denominator *= other.numerator;

    long commonGCD = gcd(numerator, denominator);

    numerator /= commonGCD;
    denominator /= commonGCD;

    return *this;
}

Fraction operator+(const Fraction& lf, const Fraction& rf){
    long num = lf.numerator * rf.denominator + lf.denominator * rf.numerator;
    long dem = lf.denominator * rf.denominator;
    return Fraction(num, dem);
}

Fraction operator-(const Fraction& lf, const Fraction& rf){
    long num = lf.numerator * rf.denominator - lf.denominator * rf.numerator;
    long dem = lf.denominator * rf.denominator;
    return Fraction(num, dem);
}

Fraction operator*(const Fraction& lf, const Fraction& rf){
    long num = lf.numerator * rf.numerator;
    long dem = lf.denominator * rf.denominator;
    return Fraction(num, dem);
}

Fraction operator/(const Fraction& lf, const Fraction& rf){
    long num = lf.numerator * rf.denominator;
    long dem = lf.denominator * rf.numerator;
    return Fraction(num, dem);
}

Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

istream& operator>>(istream& in, Fraction& f1) {
    cout << "Digite o numerador: ";
    in >> f1.numerator;
    
    cout << "Digite o denominador: ";
    in >> f1.denominator;

    if (f1.denominator == 0) {
        cerr << "Erro: O denominador não pode ser 0." << std::endl;
        exit(EXIT_FAILURE);
    }

    return in;
}

ostream& operator<<(ostream& out, const Fraction& f1) {
    out << f1.numerator << "/" << f1.denominator;
    return out;
}

Fraction::~Fraction(){
    cout << "Fração destruída" << endl;
}




