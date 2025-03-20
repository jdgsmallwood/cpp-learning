#include "util.h"
#include <gtest/gtest.h>

TEST(CalculateDistanceTest, HandlesValidVectors)
{
  std::vector<int> data_1 = {1, 2, 3};
  std::vector<int> data_2 = {1, 2, 3};

  int result = calculateDistance(data_1, data_2);
  EXPECT_EQ(result, 0);
}

TEST(CalculateDistanceTest, SimilarityScoreFalseIsOriginalFunction)
{
  std::vector<int> data_1 = {1, 2, 3};
  std::vector<int> data_2 = {1, 2, 3};

  int result = calculateDistance(data_1, data_2, false);
  EXPECT_EQ(result, 0);
}

TEST(CalculateSimilarityScoreTest, Prob1BExample)
{
  std::vector<int> data_1 = {3, 4, 2, 1, 3, 3};
  std::vector<int> data_2 = {4, 3, 5, 3, 9, 3};

  int result = calculateDistance(data_1, data_2, true);
  EXPECT_EQ(result, 31);
}