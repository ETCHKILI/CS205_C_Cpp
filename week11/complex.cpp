//
// Created by GuoYubin on 2021/4/29.
//

#include "complex.h"

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex Complex::operator+(double re) const {
    return Complex(this->real + re, this->imag);
}

Complex Complex::operator-(double re) const {
    return Complex(this->real - re, this->imag);
}

Complex Complex::operator*(double re) const {
    return Complex(this->real * re, this->imag * re);
}

bool Complex::operator==(const Complex &rhs) const {
    return real == rhs.real &&
           imag == rhs.imag;
}

bool Complex::operator!=(const Complex &rhs) const {
    return !(rhs == *this);
}

Complex operator +(double re, const Complex &other) {
    return Complex(re + other.real, other.imag);
}

Complex operator +(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator -(double re, const Complex &other) {
    return Complex(re - other.real, 0 - other.imag);
}

Complex operator -(const Complex &c1, const Complex &c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator*(double re, const Complex &other) {
    return Complex(other.real * re, other.imag * re);
}

Complex operator*(const Complex &c1, const Complex &c2) {
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c2.real * c1.imag);
}

std::ostream &operator << (std::ostream &os, const Complex &complex) {
    os << complex.real;


    if (complex.imag == 0) {
        return os;
    }
    if (complex.imag < 0) {
        os << complex.imag << 'i';
        return os;
    }

    os << "+" << complex.imag << 'i';
    return os;

}

std::istream &operator>>(std::istream &istream, Complex &complex) {
    std::cout << "The real part:\n";
    istream >> complex.real;
    std::cout << "The imag part:\n";
    istream >> complex.imag;
    return istream;
}

Complex Complex::operator~() const {
    return Complex(this->real, 0 - this->imag);
}


