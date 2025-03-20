#include <iostream>
#include <regex>
#include <string>

int get_mul_sums(std::string &input) {

  // (\d+) is a capture group to extract a portion of this string.
  std::regex pattern(R"(mul\((\d+),(\d+)\))");
  std::smatch matches;

  std::string::const_iterator searchStart(input.cbegin());
  int sum = 0;
  while (std::regex_search(searchStart, input.cend(), matches, pattern)) {
    sum += std::stoi(matches[1]) * std::stoi(matches[2]);

    // matches.suffix gives the part after the last match. We move to the first
    // part of that memory.
    searchStart = matches.suffix().first;
  }

  return sum;
}

int get_mul_sums(std::string &input, bool do_donot_enabled) {

  if (!do_donot_enabled)
    return get_mul_sums(input);

  std::regex pattern(R"(do\(\)|don't\(\))");

  auto words_begin = std::sregex_iterator(input.begin(), input.end(), pattern);
  auto words_end = std::sregex_iterator();

  size_t prev_end = 0;
  int sum = 0;

  std::string prev_match;
  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::string match = i->str();
    std::cout << match << std::endl;
    size_t match_start = i->position();

    if (prev_end == 0 || prev_match == "do()") {
      std::string substring = input.substr(prev_end, match_start - prev_end);
      sum += get_mul_sums(substring);
    }
    prev_match = match;
    prev_end = match_start + match.length();
  }

  if (prev_end < input.size()) {
    if (prev_match == "do()") {
      std::string substring = input.substr(prev_end, input.size() - prev_end);
      sum += get_mul_sums(substring);
    }
  }

  return sum;
}