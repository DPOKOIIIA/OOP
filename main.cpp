#include <iostream>
#include <stdexcept>
#include "plant_growth.h"

int main() {
    try {
        int upSpeed = 0;
        int downSpeed = 0;
        int desiredHeight = 0;
        
        // Чтение входных данных
        std::cin >> upSpeed >> downSpeed >> desiredHeight;
        
        if (std::cin.fail()) {
            throw std::invalid_argument("Некорректный ввод данных");
        }
        
        simulatePlantGrowth(upSpeed, downSpeed, desiredHeight);
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }
}