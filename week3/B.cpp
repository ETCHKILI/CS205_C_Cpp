#include <iostream>
using namespace std;

struct CandyBar
{
  char name[20];
  double weight;
  int calories;
};

int main()
{
    CandyBar candy_bar;
    cout << "Enter brand name of a Candy Bar: ";
    cin.getline(candy_bar.name,20);

    cout << "Enter weight of the Candy Bar: ";
    cin >> candy_bar.weight;

    cout << "Enter calories (an Integer value) in the Candy Bar: ";
    cin >> candy_bar.calories;

    cout << "The information you enter is:" << endl;
    cout << "Brand: " << candy_bar.name << endl;
    cout << "Weight: " << candy_bar.weight << endl;
    cout << "Calories: " << candy_bar.calories << endl;    

    return 0;
}