#include <iostream>
#include <cstring>

int main(){
    using namespace std;


    int sum = 0;
    string temp = " ";
    cout << "Enter your words (to stop, enter \"done\") : ";

    cin >> temp;
    while(temp != "done"){
        sum += 1;
        cin >> temp;
    }

    cout << "You entered a total of " << sum << " words." << endl;
}
