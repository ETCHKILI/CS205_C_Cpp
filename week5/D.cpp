#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

int main(){
    cout << "Please input your string: " << endl;
    string str;
    string str2;

    getline(cin, str);
    str2 = str;
    std::for_each(str2.begin(), str2.end(), [](char & c) {
        c = ::toupper(c);
    });

    std::ofstream f1 ("e:\\f1.txt");
    f1 << str << std::endl;
    f1.close();

    std::ofstream f2 ("e:\\f2.txt");
    f2 << str2 << std::endl;
    f2.close();

    cout << str << endl;
    cout << str2 << endl;


}