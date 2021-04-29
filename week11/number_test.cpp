//
// Created by GuoYubin on 2021/4/29.
//
#include "number.h"
#include <iostream>

using namespace std;
int main() {
    Number n1(20);

    Number n2 = n1++;
    cout << n1 << '\n' << n2 << '\n';

    Number n3 = n2--;
    cout << n2 << '\n' << n3 << '\n';

    Number n4 = ++n3;
    cout << n3 << '\n' << n4 << '\n';

    Number n5 = --n4;
    cout << n4 << '\n' << n5 << '\n';

}