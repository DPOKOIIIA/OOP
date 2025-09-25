#include <iostream>
#include <stdexcept>
#include "plant_growth.h"

using namespace std;

int main() {
    int upSpeed, downSpeed, desiredHeight;
    cin >> upSpeed >> downSpeed >> desiredHeight;
    if (!cin) {
        cerr << "Ошибка: некорректный ввод данных\n";
        return 1;
    }
    if (upSpeed <= 0) {
        cerr << "Ошибка: скорость роста должна быть положительной\n";
        return 1;
    }
    if (downSpeed < 0 || desiredHeight < 0) {
        cerr << "Ошибка: скорости и высота не могут быть отрицательными\n";
        return 1;
    }
    simulatePlantGrowth(upSpeed, downSpeed, desiredHeight);
    return 0;
}