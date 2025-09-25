cmake_minimum_required(VERSION 3.16)
project(PlantGrowth LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Более мягкая проверка версии GCC
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "13.0")
        message(WARNING "Рекомендуется GCC 13 или выше. Текущая версия: ${CMAKE_CXX_COMPILER_VERSION}")
    endif()
endif()

# Основная программа
add_executable(plant_growth main.cpp plant_growth.cpp)

# Тестовая программа
enable_testing()
find_package(GTest REQUIRED)
add_executable(plant_growth_tests test_plant_growth.cpp plant_growth.cpp)
target_link_libraries(plant_growth_tests GTest::gtest GTest::gtest_main)
add_test(NAME PlantGrowthTests COMMAND plant_growth_tests)