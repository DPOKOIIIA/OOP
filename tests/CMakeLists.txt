find_package(GTest REQUIRED)
add_executable(test_decimal test.cpp)
target_link_libraries(test_decimal Decimal GTest::GTest GTest::Main)
include(GoogleTest)
gtest_discover_tests(test_decimal
    TEST_PREFIX "Decimal_"
    TEST_SUFFIX ""
    DISCOVERY_MODE PRE_TEST
)