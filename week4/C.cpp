#include <iostream>

int main()
{
    using namespace std;

    auto arr_p = new int[5];

    for (int i = 0; i < 5; ++i)
    {
        cin >> *(arr_p + i);
    }

    for (int i = 4; i >= 0 ; --i)
    {
        cout << *(arr_p + i) << " ";
    }

    cout << endl;
    delete [] arr_p;
}