#include "candybar.h"

int main(){
    CandyBar candy_bar{};
    setCandyBar(candy_bar);
    showCandyBar(candy_bar);
    setCandyBar(&candy_bar);
    showCandyBar(&candy_bar);
}