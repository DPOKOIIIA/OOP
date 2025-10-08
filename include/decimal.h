#ifndef DECIMAL_H
#define DECIMAL_H
#include <initializer_list>
#include <string>

class Decimal {
private:
    unsigned char* digits;
    size_t size;
    
    void removeLeadingZeros();
public:
    Decimal();
    Decimal(const size_t& n, unsigned char value = 0);
    Decimal(const std::initializer_list<unsigned char>& items);
    Decimal(const std::string& value);
    Decimal(const Decimal& other);
    Decimal(Decimal&& other) noexcept;
    ~Decimal() noexcept;
    Decimal add(const Decimal& other) const;
    Decimal subtract(const Decimal& other) const;
    bool equals(const Decimal& other) const;
    bool lessThan(const Decimal& other) const;
    bool greaterThan(const Decimal& other) const;
    std::string toString() const;
    size_t getSize() const;
};
#endif