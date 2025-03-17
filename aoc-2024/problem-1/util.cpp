#include <algorithm>
#include <cmath>
#include <vector>

int calculateDistance(std::vector<int> &data_1, std::vector<int> &data_2) {
  std::sort(data_1.begin(), data_1.end());
  std::sort(data_2.begin(), data_2.end());

  int sum = 0;
  for (int i = 0; i < data_1.size(); i++) {
    sum += std::abs(data_1[i] - data_2[i]);
  }

  return sum;
}