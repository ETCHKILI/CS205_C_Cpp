//
// Created by GuoYubin on 2021/4/29.
//

#include "number.h"

Number::Number() : n(0) {}

Number::Number(int n) : n(n) {}

std::ostream &operator<<(std::ostream &os, const Number &number) {
    os << number.n;
    return os;
}

Number Number::operator++() {
    this->n ++;
    return Number(this->n);
}


Number Number::operator--() {
    this->n --;
    return Number(this->n);
}

Number Number::operator++(int a) {
    int i = this->n;
    this->n++;
    return Number(i);
}

Number Number::operator--(int a) {
    int i = this->n;
    this->n--;
    return Number(i);
}


