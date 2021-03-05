#include <iostream>
using namespace std;

int main()
{
    char first_name[20],last_name[20],grade;
    int age;

    cout << "What is your first name? ";
    cin.getline(first_name,20);
    
    cout << "What is your last name? ";
    cin >> last_name;

    cout << "What letter grade do you deserve? ";
    cin >> grade;

    cout << "What is your age? ";
    cin >> age;

    cout << "The information you enter is:" << endl;
    cout << "name: " << first_name << ", " << last_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}