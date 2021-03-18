#include <iostream>

struct pizza
{
    char name[20];
    int diameter;
    double weight;
};

int main()
{
    using namespace std;

    auto pizza_p = new pizza;

    cout << "Enter name: " << endl;
    cin.getline( (*pizza_p).name , 20 );

    cout << "Enter diameter: " << endl;
    cin >> (*pizza_p).diameter;
    cin.ignore(100,'\n');

    cout << "Enter weight(g): " << endl;
    cin >> (*pizza_p).weight;
    cin.ignore(100,'\n');

    cout << "name: " << pizza_p->name << endl;
    cout << "diameter: " << pizza_p->diameter << endl;
    cout << "weight: " << pizza_p->weight << endl;

    delete pizza_p;
}