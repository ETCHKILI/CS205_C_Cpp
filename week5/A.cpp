#include <iostream>

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    int sum = 0;
    int t = 1;
    while(t){
        cout << "Enter the number: " << endl;
        cin >> t;
        sum += t;
        cout << "The cumulative sum is: " << sum << endl;
    }

    return 0;
}