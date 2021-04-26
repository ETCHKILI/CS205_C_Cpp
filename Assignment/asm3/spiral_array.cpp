// OS: Windows 10 (64)
//
// Compiler: g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
//
// use this command to compile it:
// g++ spiral_array.cpp -o spiral_array

// use 1-D array to simulate 2-D array.
#define GET_MATRIX(x, y) matrix[(x) * n + (y)]
#include <iostream>
using namespace std;

// the variables
int m, n, cnt = 0;
int *matrix;

// check if the destination is valid
bool check(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y< n && GET_MATRIX(x, y) == 0;
}

// simulate the path of the run.
void run(int x, int y, int dir) {
    GET_MATRIX(x, y) = ++cnt;

    switch (dir) {
        // right to left
        case 0:
            if (check(x, y - 1)) {
                run(x, y - 1, 0);
                break;
            }

        // up to down
        case 1:
            if (check(x + 1, y)) {
                run(x + 1, y, 1);
                break;
            }

        // left to right
        case 2:
            if (check(x, y + 1)) {
                run(x, y + 1, 2);
                break;
            }

        // case 3: down to up
        default:
            if (check(x - 1, y)) {
                run(x - 1, y, 3);
                break;
            } else if (check(x, y - 1)) {
                run(x, y - 1, 0);
                break;
            }
    }
}

int main() {
    cin >> m >> n;
    matrix = new int [m * n] {0};

    if (m <= 0 || n <= 0) {
        cout << "invalid input\n";
        return 0;
    }

    run(0, n - 1, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%-3d", GET_MATRIX(i, j));
        }
        cout << '\n';
    }

    delete[] matrix;

    cout << "press enter to quit.\n";
    cin.get();
    cin.get();

    return 0;
}
