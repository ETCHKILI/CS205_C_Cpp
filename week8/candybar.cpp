#include "candybar.h"
using namespace std;

void setCandyBar (CandyBar &cb) {
    cout << "Enter brand name of a Candy Bar:\n";
    cin.getline(cb.brand,LEN);

    cout << "Enter weight of the Candy Bar:\n";
    cin >> cb.weight;
    cin.ignore();

    cout << "Enter calories (an Integer value) in the Candy Bar:\n";
    cin >> cb.calorie;
    cin.ignore();
}
void setCandyBar (CandyBar *cb) {
    cout << "Enter brand name of a Candy Bar:\n";
    cin.getline(cb->brand,LEN);

    cout << "Enter weight of the Candy Bar:\n";
    cin >> cb->weight;
    cin.ignore();

    cout << "Enter calories (an Integer value) in the Candy Bar:\n";
    cin >> cb->calorie;
    cin.ignore();
}
void showCandyBar (const CandyBar &cb) {
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calorie << endl;
}
void showCandyBar (const CandyBar *cb) {
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "Calories: " << cb->calorie << endl;
}