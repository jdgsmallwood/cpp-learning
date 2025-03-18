#include "util.h"
#include <gtest/gtest.h>

TEST(IsReportSafeTest, FirstExample) {

  std::vector<int> report = {7, 6, 4, 2, 1};

  bool safe = isReportSafe(report);
  EXPECT_EQ(safe, 1);
}

TEST(IsReportSafeTest, SecondExample) {

  std::vector<int> report = {1, 2, 7, 8, 9};

  bool safe = isReportSafe(report);
  EXPECT_EQ(safe, 0);
}

TEST(IsReportSafeTest, ThirdExample) {

  std::vector<int> report = {9, 7, 6, 2, 1};

  bool safe = isReportSafe(report);
  EXPECT_EQ(safe, 0);
}

TEST(IsReportSafeTest, FourthExample) {

  std::vector<int> report = {1, 3, 2, 4, 5};

  bool safe = isReportSafe(report);
  EXPECT_EQ(safe, 0);
}

TEST(IsReportSafeTest, FifthExample) {

  std::vector<int> report = {8, 6, 4, 4, 1};

  bool safe = isReportSafe(report);
  EXPECT_EQ(safe, 0);
}

TEST(IsReportSafeTest, SixthExample) {

  std::vector<int> report = {1, 3, 6, 7, 9};

  bool safe = isReportSafe(report);
  EXPECT_EQ(safe, 1);
}

TEST(IsReportSafeTest, FirstExampleDamped) {

  std::vector<int> report = {7, 6, 4, 2, 1};

  bool safe = isReportSafe(report, true);
  EXPECT_EQ(safe, 1);
}

TEST(IsReportSafeTest, SecondExampleDamped) {

  std::vector<int> report = {1, 2, 7, 8, 9};

  bool safe = isReportSafe(report, true);
  EXPECT_EQ(safe, 0);
}

TEST(IsReportSafeTest, ThirdExampleDamped) {

  std::vector<int> report = {9, 7, 6, 2, 1};

  bool safe = isReportSafe(report, true);
  EXPECT_EQ(safe, 0);
}

TEST(IsReportSafeTest, FourthExampleDamped) {

  std::vector<int> report = {1, 3, 2, 4, 5};

  bool safe = isReportSafe(report, true);
  EXPECT_EQ(safe, 1);
}

TEST(IsReportSafeTest, FifthExampleDamped) {

  std::vector<int> report = {8, 6, 4, 4, 1};

  bool safe = isReportSafe(report, true);
  EXPECT_EQ(safe, 1);
}

TEST(IsReportSafeTest, SixthExampleDamped) {

  std::vector<int> report = {1, 3, 6, 7, 9};

  bool safe = isReportSafe(report, true);
  EXPECT_EQ(safe, 1);
}