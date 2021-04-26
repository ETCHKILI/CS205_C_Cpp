//
// Created by GuoYubin on 2021/4/22.
//
#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle() {
    width = 1;
    height = 1;
}
Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

double Rectangle::getArea() {
    return width * height;
}

double Rectangle::getPerimeter() {
    return 2 * (width + height);
}

void Rectangle::display() {
    std::cout << "-------------\n"
        << "width: " << this->width << "\n" << "height: " << this->height << '\n' << "area:" << this->getArea() << '\n' << "perimeter:" << this->getPerimeter() << '\n'
        << "-------------\n";
}

std::ostream &operator<<(std::ostream &os, Rectangle &rectangle) {
    os << "-------------\n";
    os << "width: " << rectangle.width << "\n" << "height: " << rectangle.height << '\n' << "area:" << rectangle.getArea() << '\n' << "perimeter:" << rectangle.getPerimeter() << '\n';
    os << "-------------\n";
    return os;
}
