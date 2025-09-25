#include "plant_growth.h"
#include <iostream>

using namespace std;

void simulatePlantGrowth(int upSpeed, int downSpeed, int desiredHeight) {
    if (upSpeed <= 0) {
        throw invalid_argument("Скорость роста должна быть положительной");
    }
    if (downSpeed < 0 || desiredHeight < 0) {
        throw invalid_argument("Скорость уменьшения и высота не могут быть отрицательными");
    }
    int currentHeight = 0;
    int day = 0;
    while (currentHeight < desiredHeight) {
        ++day;
        currentHeight += upSpeed;
        cout << "После дня " << day << " --> " << currentHeight << " м\n";
        if (currentHeight >= desiredHeight) {
            break;
        }
        currentHeight -= downSpeed;
        if (currentHeight < 0) {
            currentHeight = 0;
        }
        cout << "После ночи " << day << " --> " << currentHeight << " м\n";
        if (day > 100000) {
            throw runtime_error("Слишком большое количество дней");
        }
    }
}