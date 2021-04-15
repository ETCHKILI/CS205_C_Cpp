#include "golf.h"
#include <iostream>


int main() {
    golf g{};
    SetGolf(g, "Andy Baffy", 24);
    ShowGolf(g);

    while(!SetGolf(g)) {}
    ShowGolf(g);
    std::cin.get();
}