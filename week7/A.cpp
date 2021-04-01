#include <iostream>
#include <cstring>

using namespace std;

struct stringy{
    char *str;
    int ct;
};

void set(stringy &beany, const char* str);
void show(const char* str, int cnt = 1);
void show(stringy beany, int cnt = 1);



int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(stringy &beany, const char* str) {
    beany.ct = strlen(str);
    auto tmp = new char[beany.ct];
    strcpy(tmp, str);
    beany.str = tmp;
}

void show(const stringy beany, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        cout << beany.str << '\n';
    }
}

void show(const char* str, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        cout << str << '\n';
    }
}