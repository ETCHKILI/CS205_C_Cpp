// 11912726
// Guo Yubin
// c++ 17, gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0

#include <iostream>
#include <cmath>
#include <cstring>

const int kEarthRadiusInKM = 6371;

struct City {
    char name[40];
    double latitude;
    double longitude;
    double phi;
    double theta;
};

double ConvertDegreesToRadians(double);
void CalculateInformation(City*);
bool GetInformation(City*, int);
double CalculateDistance(City*, City*);


int main() {
    City city1{}, city2{};
    if (!GetInformation(&city1, 1) || !GetInformation(&city2, 2)) {
        return 0;
    }
    std::cout << "The distance is: " << CalculateDistance(&city1, &city2) << '\n';
}

//return false if that string contains invalid character(s);
int CheckString(const char *str) {
    int i;
    for (i = 0; i < strlen(str); ++i) {
        if (isalnum(str[i]) || str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '\'') {
            continue;
        }
        return i;
    }
    return i;
}

double ConvertDegreesToRadians(double a) {
    return a * M_PI / 180;
}

// Calculate the phi and theta and store in the pass-in City
void CalculateInformation(City *city) {
    city->phi = ConvertDegreesToRadians(90 - city->latitude);
    city->theta = ConvertDegreesToRadians(city->longitude);
}

// Get city pointer and fill the data in,
// if the data is invalid, output the warnings and return false,
// if successfully fill the data in, return true
bool GetInformation(City *city, int id) {
    using std::cin;
    using std::cout;
    using namespace std;

    cout << "City #" << id << '\n';

    cout << "The name of the city (Numbers, English letters and single space are valid):\n";
    cin.getline(city->name, 40);
    int wrong_index = CheckString(city->name);
    if (wrong_index != strlen(city->name)) {
        cout << "Invalid name: your character " << city->name[wrong_index] << "is invalid!";
        return false;
    }

    cout << "The latitude and longitude of the city (Two double values, separated by space):\n";
    cin >> city->latitude >> city->longitude;
    cin.ignore(100, '\n');

    if (cin.fail()) {
        cin.clear();
        cout << "Invalid input!\n";
        return false;
    }

    if (city->latitude < -90 || city->latitude > 90 || city->longitude < -180 || city->longitude > 180) {
        cout << "Check your location data! (0 <= phi <= 180, -180 <= theta <= 180)\n";
    }
    return true;
}

// Input two city pointer, return the distance calculated by there location data
double CalculateDistance(City *city1, City *city2) {
    CalculateInformation(city1);
    CalculateInformation(city2);
    return kEarthRadiusInKM * acos(sin(city1->phi) * sin(city2->phi)
            * cos(city1->theta - city2->theta)
            + cos(city1->phi) * cos(city2->phi));
}