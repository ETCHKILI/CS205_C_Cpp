//
// Created by GuoYubin on 2021/4/22.
//
#include "rectangle.h"
#include <iostream>

int main() {
    Rectangle r1(4, 40);
    Rectangle r2(3.5, 35.9);

    std::cout << r1;
    std::cout << r2;

    r1.display();
    r2.display();
}
