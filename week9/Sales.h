namespace SALES{
    const int kQuarters = 4;
    struct Sales {
        double sales[kQuarters];
        double average;
        double max;
        double min;
    };

    void SetSales(Sales &s, const double ar[], int n);
    void SetSales(Sales &s);
    void ShowSales(const Sales &s);
}
