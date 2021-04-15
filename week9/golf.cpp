#include <iostream>
#include <cstring>
#include "golf.h"

void SetGolf(golf &g, const char* name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
}


int SetGolf(golf &g) {
    char tmp1[kLen] = "";
    char tmp2[kLen] = "";

    std::cout << "Fullname:";
    std::cin.getline(tmp1, 40);
    std::cout << "Handicap:";
    std::cin.getline(tmp2, 10);

    if (strcmp(tmp1, "") == 0 || strcmp(tmp2, "") == 0) {
        return 0;
    }
    strcpy(g.fullname, tmp1);
    g.handicap = atoi(tmp2);
    return 1;
}

void Handicap(golf &g, int hc) {
    g.handicap = hc;
}

void ShowGolf(const golf &g) {
    std::cout << "The name of the golf is " << g.fullname << " and its handicap is " << g.handicap << '\n';
}