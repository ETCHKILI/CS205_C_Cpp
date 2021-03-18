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
    CandyBar max;
    double rate=0;

    auto candys_p = new CandyBar[3];

//    CandyBar c1, c2, c3;
//    CandyBar candy_bars[3]{c1,c2,c3};

    for (int i = 0; i < 3; ++i)
    {
        string ss;

        cout << "Enter brand name of a Candy Bar: ";
        cin.getline(candys_p[i].name,20);

        cout << "Enter weight of the Candy Bar: ";
        cin >> candys_p[i].weight ;
        cin.ignore(100,'\n');

        cout << "Enter calories (an Integer value) in the Candy Bar: ";
        cin >> candys_p[i].calories;
        cin.ignore(100,'\n');

        if (candys_p[i].calories / candys_p[i].weight > rate)
        {
            rate = candys_p[i].calories / candys_p[i].weight;
            max = candys_p[i];
        }

    }

    cout << "The information you enter is:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Brand: " << candys_p[i].name << endl;
        cout << "Weight: " << candys_p[i].weight << endl;
        cout << "Calories: " << candys_p[i].calories << endl;
    }

    cout << "The greatest: " << endl;
    cout << "Name: " << max.name << endl;
    cout << "cal/weight: " << rate << endl;

    delete [] candys_p;
    return 0;
}