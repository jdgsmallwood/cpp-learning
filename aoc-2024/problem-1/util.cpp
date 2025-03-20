#include <algorithm>
#include <cmath>
#include <vector>

int calculateDistance(std::vector<int> &data_1, std::vector<int> &data_2)
{
  std::sort(data_1.begin(), data_1.end());
  std::sort(data_2.begin(), data_2.end());

  int sum = 0;
  for (int i = 0; i < data_1.size(); i++)
  {
    sum += std::abs(data_1[i] - data_2[i]);
  }

  return sum;
}

int calculateDistance(std::vector<int> &data_1, std::vector<int> &data_2, bool similarityScore)
{
  if (!similarityScore)
    return calculateDistance(data_1, data_2);

  std::sort(data_1.begin(), data_1.end());
  std::sort(data_2.begin(), data_2.end());

  int sum = 0;
  int right_pointer = 0;
  int left_pointer = 0;

  while (left_pointer < data_1.size())
  {
    int num_same_value = 1;
    while (left_pointer + num_same_value < data_1.size() && data_1[left_pointer] == data_1[left_pointer + num_same_value])
      num_same_value++;

    int right_values = 0;
    while (right_pointer < data_2.size() && data_2[right_pointer] < data_1[left_pointer])
    {
      right_pointer++;
    }
    while (data_2[right_pointer] == data_1[left_pointer])
    {

      right_values++;
      right_pointer++;
    }

    sum += num_same_value * right_values * data_1[left_pointer];

    left_pointer += num_same_value;
  }

  return sum;
}