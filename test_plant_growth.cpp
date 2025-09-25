#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "plant_growth.h"

class PlantGrowthTest : public ::testing::Test {
protected:
    std::string captureOutput(int upSpeed, int downSpeed, int desiredHeight) {
        std::ostringstream output;
        auto oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        
        try {
            simulatePlantGrowth(upSpeed, downSpeed, desiredHeight);
        } catch (...) {
            std::cout.rdbuf(oldCoutBuffer);
            throw;
        }
        
        std::cout.rdbuf(oldCoutBuffer);
        return output.str();
    }
};

TEST_F(PlantGrowthTest, BasicExampleFromTask) {
    std::string output = captureOutput(100, 10, 910);
    
    EXPECT_TRUE(output.find("После дня 1 --> 100 м") != std::string::npos);
    EXPECT_TRUE(output.find("После ночи 1 --> 90 м") != std::string::npos);
    EXPECT_TRUE(output.find("После дня 10 --> 910 м") != std::string::npos);
}

TEST_F(PlantGrowthTest, ReachesInFirstDay) {
    std::string output = captureOutput(100, 10, 50);
    EXPECT_TRUE(output.find("После дня 1 --> 100 м") != std::string::npos);
    EXPECT_TRUE(output.find("После ночи 1") == std::string::npos);
}

TEST_F(PlantGrowthTest, ExactHeightAtEndOfDay) {
    std::string output = captureOutput(100, 10, 100);
    EXPECT_TRUE(output.find("После дня 1 --> 100 м") != std::string::npos);
    EXPECT_TRUE(output.find("После ночи 1") == std::string::npos);
}