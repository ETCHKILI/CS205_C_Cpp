//
// Created by GuoYubin on 2021/4/29.
//

#ifndef SUSTECH_CS205_CPP_SPRING_2021_CPP_NUMBER_H
#define SUSTECH_CS205_CPP_SPRING_2021_CPP_NUMBER_H

#include <ostream>

class Number {
public:
    Number(int n);

    Number();

    friend std::ostream &operator<<(std::ostream &os, const Number &number);

private:
    int n;

public:
    Number operator ++();
    Number operator ++(int);

    Number operator --();
    Number operator --(int);

};

#endif //SUSTECH_CS205_CPP_SPRING_2021_CPP_NUMBER_H
