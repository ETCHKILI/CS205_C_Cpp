#include "Sales.h"

using namespace SALES;
int main() {
    double d[4] = {1.1, 2.2, 3.3};
    Sales s{};
    SetSales(s, d, 3);
    ShowSales(s);
    SetSales(s);
    ShowSales(s);
}