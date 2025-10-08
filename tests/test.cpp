#include <gtest/gtest.h>
#include "decimal.h"

TEST(DecimalTest, ConstructorFromString) {
    Decimal d("123");
    EXPECT_EQ(d.toString(), "123");
}

TEST(DecimalTest, Addition) {
    Decimal a("999");
    Decimal b("1");
    Decimal result = a.add(b);
    EXPECT_EQ(result.toString(), "1000");
}

TEST(DecimalTest, Subtraction) {
    Decimal a("1000");
    Decimal b("1");
    Decimal result = a.subtract(b);
    EXPECT_EQ(result.toString(), "999");
}

TEST(DecimalTest, Comparison) {
    Decimal a("100");
    Decimal b("50");
    EXPECT_TRUE(a.greaterThan(b));
    EXPECT_TRUE(b.lessThan(a));
    EXPECT_TRUE(a.equals(Decimal("100")));
}