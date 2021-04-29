//
// Created by GuoYubin on 2021/4/29.
//
#include <iostream>

#ifndef SUSTECH_CS205_CPP_SPRING_2021_CPP_COMPLEX_H
#define SUSTECH_CS205_CPP_SPRING_2021_CPP_COMPLEX_H

class Complex {
private:
    double real;
    double imag;

public:
    Complex();

    Complex(double re, double im);

    Complex operator +(double re) const;
    friend Complex operator +(double re, const Complex &other);
    friend Complex operator +(const Complex &c1, const Complex &c2);

    Complex operator -(double re) const;
    friend Complex operator -(double re, const Complex &other);
    friend Complex operator -(const Complex &c1, const Complex &c2);

    Complex operator *(double re) const;
    friend Complex operator *(double re, const Complex &other);
    friend Complex operator *(const Complex &c1, const Complex &c2);

    Complex operator ~() const;

    friend std::ostream &operator<<(std::ostream &os, const Complex &complex);

    friend std::istream &operator >> (std::istream &is, Complex &complex);

    bool operator==(const Complex &rhs) const;

    bool operator!=(const Complex &rhs) const;
};

#endif //SUSTECH_CS205_CPP_SPRING_2021_CPP_COMPLEX_H
