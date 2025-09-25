#include "plant_growth.h"
#include <iostream>

void simulatePlantGrowth(int upSpeed, int downSpeed, int desiredHeight) {
    if (upSpeed <= 0) {
        throw std::invalid_argument("Скорость роста должна быть положительной");
    }
    if (downSpeed < 0 || desiredHeight < 0) {
        throw std::invalid_argument("Скорость уменьшения и высота не могут быть отрицательными");
    }
    
    int currentHeight = 0;
    int day = 0;
    
    while (currentHeight < desiredHeight) {
        ++day;
        
        // День: растение растет
        currentHeight += upSpeed;
        std::cout << "После дня " << day << " --> " << currentHeight << " м\n";
        
        // Проверка достижения высоты днем
        if (currentHeight >= desiredHeight) {
            break;
        }
        
        // Ночь: растение уменьшается
        currentHeight -= downSpeed;
        if (currentHeight < 0) {
            currentHeight = 0;
        }
        std::cout << "После ночи " << day << " --> " << currentHeight << " м\n";
        
        // Защита от бесконечного цикла
        if (day > 100000) {
            throw std::runtime_error("Слишком большое количество дней");
        }
    }
}