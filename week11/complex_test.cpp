//
// Created by GuoYubin on 2021/4/29.
//
using namespace std;
#include "complex.h"

int main() {
    Complex a(3, 4);
    Complex b(2, 6);

    cout << a << '\n';
    cout << b << '\n';
    cout << ~b << '\n';
    cout << a + b << '\n';
    cout << a - b << '\n';
    cout << a - 2 << '\n';
    cout << a * b << '\n';
    cout << 2 * a << '\n';

    Complex c = b;
    cout << (b == c) << '\n';
    cout << (b != c) << '\n';
    cout << (a == c) << '\n';


    Complex d;
    cin >> d;
    cout << d;
}