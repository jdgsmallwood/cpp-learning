#include "util.h"
#include <gtest/gtest.h>

TEST(TestNothing, HappyDays) { EXPECT_EQ(0, 0); }

TEST(CalculateDistanceTest, HandlesValidVectors) {
  std::vector<int> data_1 = {1, 2, 3};
  std::vector<int> data_2 = {1, 2, 3};

  int result = calculateDistance(data_1, data_2);
  EXPECT_EQ(result, 0);
}