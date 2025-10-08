#include "decimal.h"
#include <stdexcept>
#include <algorithm>

Decimal::Decimal() : size(1) {
    digits = new unsigned char[1];
    digits[0] = 0;
}
Decimal::Decimal(const size_t& n, unsigned char value) : size(n) {
    if (value > 9) throw std::invalid_argument("Digit must be 0-9");
    digits = new unsigned char[n];
    std::fill(digits, digits + n, value);
    removeLeadingZeros();
}
Decimal::Decimal(const std::initializer_list<unsigned char>& items) : size(items.size()) {
    digits = new unsigned char[size];
    size_t i = 0;
    for (auto it = items.end() - 1; it >= items.begin(); --it) {
        if (*it > 9) throw std::invalid_argument("Digit must be 0-9");
        digits[i++] = *it;
    }
    removeLeadingZeros();
}
Decimal::Decimal(const std::string& value) : size(value.length()) {
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        char c = value[size - 1 - i];
        if (c < '0' || c > '9') throw std::invalid_argument("Invalid digit in string");
        digits[i] = c - '0';
    }
    removeLeadingZeros();
}
Decimal::Decimal(const Decimal& other) : size(other.size) {
    digits = new unsigned char[size];
    std::copy(other.digits, other.digits + size, digits);
}
Decimal::Decimal(Decimal&& other) noexcept : digits(other.digits), size(other.size) {
    other.digits = nullptr;
    other.size = 0;
}
Decimal::~Decimal() noexcept {
    delete[] digits;
}

void Decimal::removeLeadingZeros() {
    while (size > 1 && digits[size - 1] == 0) {
        --size;
    }
    unsigned char* new_digits = new unsigned char[size];
    std::copy(digits, digits + size, new_digits);
    delete[] digits;
    digits = new_digits;
}

Decimal Decimal::add(const Decimal& other) const {
    size_t new_size = std::max(size, other.size) + 1;
    unsigned char* new_digits = new unsigned char[new_size]();
    unsigned char carry = 0;
    for (size_t i = 0; i < new_size; ++i) {
        unsigned char sum = carry;
        if (i < size) sum += digits[i];
        if (i < other.size) sum += other.digits[i];
        new_digits[i] = sum % 10;
        carry = sum / 10;
    }
    Decimal result;
    delete[] result.digits;
    result.digits = new_digits;
    result.size = new_size;
    result.removeLeadingZeros();
    return result;
}

Decimal Decimal::subtract(const Decimal& other) const {
    if (lessThan(other)) throw std::runtime_error("Negative result not allowed");
    unsigned char* new_digits = new unsigned char[size]();
    unsigned char borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        int sub = digits[i] - borrow;
        if (i < other.size) sub -= other.digits[i];
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        new_digits[i] = sub;
    }
    
    Decimal result;
    delete[] result.digits;
    result.digits = new_digits;
    result.size = size;
    result.removeLeadingZeros();
    return result;
}

bool Decimal::equals(const Decimal& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

bool Decimal::lessThan(const Decimal& other) const {
    if (size != other.size) return size < other.size;
    for (int i = size - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) 
            return digits[i] < other.digits[i];
    }
    return false;
}

bool Decimal::greaterThan(const Decimal& other) const {
    return !lessThan(other) && !equals(other);
}

std::string Decimal::toString() const {
    std::string result;
    for (int i = size - 1; i >= 0; --i) {
        result += ('0' + digits[i]);
    }
    return result;
}

size_t Decimal::getSize() const {
    return size;
}