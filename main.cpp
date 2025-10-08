#include <iostream>
#include "decimal.h"

int main() {
    try {
        Decimal a("12345");
        Decimal b("67890");
        std::cout << "a = " << a.toString() << std::endl;
        std::cout << "b = " << b.toString() << std::endl;
        Decimal sum = a.add(b);
        std::cout << "a + b = " << sum.toString() << std::endl;
        Decimal diff = b.subtract(a);
        std::cout << "b - a = " << diff.toString() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}