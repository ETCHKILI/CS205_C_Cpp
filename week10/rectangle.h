//
// Created by GuoYubin on 2021/4/22.
//

#include <ostream>

class Rectangle {
public:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double width, double height);
    double getArea();
    double getPerimeter();
    void display();

    friend std::ostream &operator<<(std::ostream &os, Rectangle &rectangle);
};
