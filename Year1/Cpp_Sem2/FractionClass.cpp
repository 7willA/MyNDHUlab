#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;

    void reduce() {
        int a = abs(num), b = abs(den), r;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        int gcd = a;
        num /= gcd;
        den /= gcd;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) { reduce(); }

    int getNumerator() const { return num; }
    int getDenominator() const { return den; }
    void setNumerator(int n) { num = n; reduce(); }
    void setDenominator(int d) { den = d; reduce(); }

    void display() const {
        if (den == 1)
            cout << "(" << num << ")";
        else
            cout << "(" << num << "/" << den << ")";
    }

    Fraction operator+(Fraction f) { return Fraction(num * f.den + f.num * den, den * f.den); }
    Fraction operator-(Fraction f) { return Fraction(num * f.den - f.num * den, den * f.den); }
    Fraction operator*(Fraction f) { return Fraction(num * f.num, den * f.den); }
    Fraction operator/(Fraction f) { return Fraction(num * f.den, den * f.num); }

    Fraction& operator=(Fraction f) {
        num = f.num;
        den = f.den;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.den == 1) os << "(" << f.num << ")";
        else os << "(" << f.num << "/" << f.den << ")";
        return os;
    }
};
