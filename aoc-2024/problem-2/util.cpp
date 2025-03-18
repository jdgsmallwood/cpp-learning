#include <cmath>
#include <vector>

bool isReportSafe(std::vector<int> &report) {

  bool set = false;
  bool ascending = false;

  for (int i = 0; i < report.size() - 1; i++) {

    int diff = report[i + 1] - report[i];

    // Should not be too large a jump between them.
    if (abs(diff) == 0 || abs(diff) > 3)
      return false;

    if (!set) {
      if (diff > 0)
        ascending = true;
      set = true;
    }

    if ((diff > 0 && !ascending) || (diff < 0 && ascending))
      return false;
  }

  return true;
}

bool isReportSafe(std::vector<int> &report, bool damped) {

  if (!damped)
    return isReportSafe(report);

  if (isReportSafe(report))
    return true;

  // Try leaving out one of each in the vector
  for (int i = 0; i < report.size(); i++) {
    std::vector<int> newVec;

    for (int j = 0; j < report.size(); j++) {
      if (j != i)
        newVec.push_back(report[j]);
    }

    if (isReportSafe(newVec))
      return true;
  }

  return false;
}