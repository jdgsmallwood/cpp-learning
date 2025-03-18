#include "util.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  std::ifstream file("../input.txt");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  std::string line;
  int sum = 0;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::vector<int> report;
    std::string item;

    while (std::getline(ss, item, ' ')) {
      if (item == "")
        continue;

      report.push_back(std::stoi(item));
    }
    sum += isReportSafe(report, true);
  }

  file.close();

  std::cout << "Num safe reports is " << sum << std::endl;

  return 0;
}