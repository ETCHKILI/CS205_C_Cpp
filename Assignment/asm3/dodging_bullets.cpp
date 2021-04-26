// OS: Windows 10 (64)
//
// Compiler: g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
//
// use this command to compile it:
// g++ dodging_bullets.cpp -o dodging_bullets


// use 1-D array to simulate 2-D array.
#define GET_MATRIX(x, y) matrix[(x) * m + (y)]
#include <iostream>

using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    auto matrix = new int[n * m]{0};

    int x, y, dx, dy, res = 0;

    // input bullets and simulate each bullets' route ballistic.
    while (k--) {
        cin >> x >> y >> dx >> dy;
        for (int i = x, j = y; i < n && i >= 0 && j < m && j >= 0; i += dx, j += dy) {
            GET_MATRIX(i, j) = 1;
        }
    }

    // count safe point
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (GET_MATRIX(i, j) == 0) {
                res += 1;
            }
        }
    }

    cout << res << '\n';
    delete[] matrix;

    // press enter to quit
    cout << "press enter to quit\n";
    cin.get();
    cin.get();
}

/*
 3 4 5
 1 1 1 -1
 1 1 -1 1
 0 3 1 0
 0 2 1 0
 0 0 -1 -1

 */
