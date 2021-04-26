//
// Created by GuoYubin on 2021/4/22.
//

#include <string>

class CandyBar {
private:
    std::string name;
    double weight;
    int calories;

public:
    void setCandyBar(const std::string &name, double weight, int calories);
    void showCandyBar();
};
