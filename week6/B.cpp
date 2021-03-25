#include <iostream>
using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void CalculateVolume(box *my_box) {
    my_box->volume = my_box->length * my_box->width * my_box->height;
}

void DisplayBox(box my_box) {
//    cout << "After setting volume\n";
    cout << "Maker: " << my_box.maker << '\n';
    cout << "Height: " << my_box.height << '\n';
    cout << "Width: " << my_box.width << '\n';
    cout << "Length: " << my_box.length << '\n';
    cout << "Volume: " << my_box.volume << '\n';
}

void GetInformation(box *my_box) {
//    cout << "Before setting volume\n";

    cout << "Please enter information: \n";
    cout << "Maker: \n";
    cin.getline(my_box->maker, 40);

    cout << "Height: \n";
    cin >> my_box->height;
    cin.ignore(100, '\n');

    cout << "Width: \n";
    cin >> my_box->width;
    cin.ignore(100, '\n');

    cout << "Length: \n";
    cin >> my_box->length;
    cin.ignore(100, '\n');

//    cout << "Volume: \n";
//    cin >> my_box.volume;
//    cin.ignore(100, '\n');
}


int main() {
    box my_box {};
    box *p_box = &my_box;

    GetInformation(p_box);
    cout << "Before setting volume\n";
    DisplayBox(my_box);

    CalculateVolume(p_box);
    cout << "After setting volume\n";
    DisplayBox(my_box);
}
