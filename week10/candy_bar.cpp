//
// Created by GuoYubin on 2021/4/22.
//
#include <iostream>
#include "candy_bar.h"

void CandyBar::setCandyBar(const std::string &name, double weight, int calories) {
    this->name = name;
    this->weight = weight;
    this->calories = calories;
}

void CandyBar::showCandyBar() {
    std::cout << "Name:" << name << '\n'
        << "Weight:" << weight << '\n'
        << "Calories:" << calories << '\n';
}
