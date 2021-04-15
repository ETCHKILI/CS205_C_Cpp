#include "Sales.h"
#include <queue>
#include <cfloat>
#include <iostream>

using namespace SALES;
void SALES::SetSales(Sales &s, const double ar[], int n) {
    std::priority_queue<double, std::vector<double>, std::less<>> pq;
    for (int i = 0; i < n; ++i) {
        if (pq.size() < kQuarters) {
            pq.push(ar[i]);
        } else if (pq.top() > ar[i]) {
            pq.pop();
            pq.push(ar[i]);
        }
    }

    double av = 0, minx = DBL_MAX, maxx = 0;
    int sz = pq.size();
    for (int i = 0; i < sz; ++i) {
        s.sales[i] = pq.top();
        pq.pop();
        minx = std::min(minx, s.sales[i]);
        maxx = std::max(maxx, s.sales[i]);
        av += s.sales[i];
    }
    av /= sz;

    s.average = av;
    s.max = maxx;
    s.min = minx;
}
void SALES::SetSales(Sales &s) {
    std::cout << "Sales(" << kQuarters << " nums):";

    double av = 0, minx = DBL_MAX, maxx = 0;
    int sz = kQuarters;
    for (double & sale : s.sales) {
        std::cin >> sale;
        minx = std::min(minx, sale);
        maxx = std::max(maxx, sale);
        av += sale;
    }
    av /= sz;

    s.average = av;
    s.max = maxx;
    s.min = minx;
}
void SALES::ShowSales(const Sales &s) {
    using std::cout;
    cout << "Sales: ";
    for (auto item : s.sales) {
        if (item == 0) {
            break;
        }
        cout << item << " ";
    }
    cout << '\n';

    cout << "Average: " << s.average << '\n';
    cout << "Max: " << s.max << '\n';
    cout << "Min: " << s.min << '\n';
}