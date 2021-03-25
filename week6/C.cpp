#include <iostream>
using namespace std;


int Fill_array(double arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        cout << "Number #" << (i + 1) << ":\n";
        cin >> arr[i];
        if (!cin) {
            break;
        }
    }

    return (i);
}
void Show_array(double *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << '\n';

}
void swap(double *arr, double* end) {
    double c = *arr;
    *arr = *end;
    *end = c;
}
void Reverse_array(double *arr, int size) {
    if (size == 0 || size == 1) {
        return;
    }

    swap(arr, arr + size - 1);
    Reverse_array(arr + 1, size - 2);
}


int main() {
    cout << "Enter the size of array:";
    int n;
    cin >> n;

    auto arr = new double[n];
    if(Fill_array(arr, n) != n) {
        cout << "Invalid input!\n";
        return 0;
    }
    Show_array(arr, n);

    Reverse_array(arr, n);
    Show_array(arr, n);
    if (n <= 2){
        Show_array(arr, n);
    } else {
        ++arr;
        Reverse_array(arr, n - 2);
        --arr;
        Show_array(arr, n);
    }

    delete [] arr;
}