#include "util.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  std::ifstream file("input.txt");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  std::string line;
  std::vector<int> data_1;
  std::vector<int> data_2;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string item;

    bool first_num = false;
    while (std::getline(ss, item, ' ')) {
      if (item == "")
        continue;

      if (!first_num) {
        data_1.push_back(std::stoi(item));
        first_num = true;
      } else {
        data_2.push_back(std::stoi(item));
      }
    }
  }

  file.close();

  int sum = calculateDistance(data_1, data_2);
  std::cout << "Distance between lists is " << sum << std::endl;

  return 0;
}