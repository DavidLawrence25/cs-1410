#include <iostream>
#include <iomanip>
#include <string>

#include "custom_libraries/user_input.h"

int main() {
  const int kYears = 5;
  const int kStartYear = 2016;

  double total_income = 0.0;
  for (int i = 0; i < kYears; ++i) {
    // Initialization of `prompt` is split up because
    // there would be too many append operations otherwise.
    std::string prompt = "Enter income for : ";
    prompt.insert(17, std::to_string(kStartYear - i));

    total_income += rose::GetDouble(
        prompt, /*conversion_failed_message=*/"Input must be a number\n");
  }

  const double kAverageIncome = total_income / kYears;

  std::cout << "Income (averaged over the past " << kYears << " years) is: $"
  << std::fixed << std::setprecision(2) << kAverageIncome;

  return 0;
}
