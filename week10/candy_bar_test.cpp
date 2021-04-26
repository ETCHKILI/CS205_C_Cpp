//
// Created by GuoYubin on 2021/4/22.
//
#include <iostream>
#include "candy_bar.h"

using namespace std;

int main() {
    CandyBar candyBar;
    string name;
    double weight;
    int cal;

    cout << "Enter name:" << endl;
    getline(cin, name);

    cout << "Enter weight:" << endl;
    cin >> weight;
    cin.ignore(100, '\n');

    cout << "Enter calories:" << endl;
    cin >> cal;
    cin.ignore(100,'\n');

    candyBar.setCandyBar(name, weight, cal);
    candyBar.showCandyBar();
}