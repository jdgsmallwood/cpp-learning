
#include "util.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::ifstream file("../input.txt");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  std::string file_contents = buffer.str();

  file.close();

  int mul_sum = get_mul_sums(file_contents, true);

  std::cout << "The sum of the muls is " << mul_sum << std::endl;
  return 0;
}