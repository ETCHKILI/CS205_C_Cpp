#include <iostream>
#include <limits>
using namespace std;

struct CandyBar
{
  char name[20];
  double weight;
  int calories;
};

int main()
{
    CandyBar max;
    double rate=0;
    CandyBar c1, c2, c3;
    CandyBar candy_bars[3]{c1,c2,c3};

    for (int i = 0; i < 3; ++i)
    {
        string ss;

        cout << "Enter brand name of a Candy Bar: ";
        cin.getline(candy_bars[i].name,20);

        cout << "Enter weight of the Candy Bar: ";
        cin >> candy_bars[i].weight ;
        cin.ignore(100,'\n');

        cout << "Enter calories (an Integer value) in the Candy Bar: ";
        cin >> candy_bars[i].calories;
        cin.ignore(100,'\n');

        if (candy_bars[i].calories / candy_bars[i].weight > rate)
        {       
            rate = candy_bars[i].calories / candy_bars[i].weight;
            max = candy_bars[i];
        }
        
    }
        
    cout << "The information you enter is:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Brand: " << candy_bars[i].name << endl;
        cout << "Weight: " << candy_bars[i].weight << endl;
        cout << "Calories: " << candy_bars[i].calories << endl;  
    }

    cout << "The greatest: " << endl;
    cout << "Name: " << max.name << endl;
    cout << "cal/weight: " << rate << endl;
    return 0;
}