#include <iostream>

using namespace std;

int main() {
    int a[4] = {2,4,6};
    int y = 0, *p = a;
        

    for(;*p++;)
        if (*p)
            y += *p;

    cout << y << endl;
        
    
        
    
}