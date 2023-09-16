#include <math.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

#include "custom_libraries/user_input.h"

// Prints the menu and returns the option the user picks.
int menu();
// Calculates the number of years until a goal is met and prints the result.
void calculate_years();
// Calculates the growth of an investment after a specified number of years
// and prints the result.
void calculate_amount();

int main() {
  std::cout << "Financial Goal Calculator\n";

  while (true) {
    switch (menu()) {
      case 1:
        calculate_years();
        break;
      case 2:
        calculate_amount();
        break;
      case 3:
      default:
        return 0;
    }
  }
}

// Prints the menu and returns the option the user picks.
// Shorthand for a specific `rose::MenuPrompt` function call.
int menu() {
  return rose::MenuPrompt(
    "1. Calculate Years to Financial Goal\n2. Calculate Amount Based on Years\n3. Quit\n",
    "Invalid input. Please try again\n",
    {{"1", 1}, {"2", 2}, {"3", 3}}
  );
}

// Calculates the number of years until a goal is met and prints the result.
// After each year, prints the investment's value.
void calculate_years() {
  const std::string kConversionFailedMessage =
      "Invalid input. Please try again\n";

  double investment = rose::GetDouble(
      "Enter Investment Amount: ", kConversionFailedMessage);
  const double kInterestRate = 0.01 * rose::GetDouble(
      "Enter Interest Rate: ", kConversionFailedMessage);
  const double kGoal = rose::GetDouble(
      "Enter Financial Goal: ", kConversionFailedMessage);

  // TODO: There may be a better way to calculate the width to print at.
  const int kGoalWidth = static_cast<int>(log10(kGoal)) + 4;

  int years = 0;
  while (investment < kGoal) {
    ++years;
    investment += investment * kInterestRate;
    std::cout << "Year " << std::setw(3) << years << ". " << std::setw(kGoalWidth)
    << std::fixed << std::setprecision(2) << investment << '\n';
  }

  if (years == 1) {
    std::cout << "That will take 1 year\n";
  } else {
    std::cout << "That will take " << years << " years\n";
  }
}

// Calculates the growth of an investment after a specified number of years
// and prints the result. Utilizes the following formula for compound interest:
// A = P(1 + r/n)^(n*t)
// Because this program only considers annually compounding interest, n = 1
// A = P(1 + r)^t
void calculate_amount() {
  double investment = rose::GetDouble(
      "Enter Investment Amount: ", "Invalid input. Please try again\n");
  const double kInterestRate = 0.01 * rose::GetDouble(
      "Enter Interest Rate: ", "Invalid input. Please try again\n");
  const int kYears = rose::GetInteger(
      "Enter Years to Maturity: ", "Invalid input. Please try again\n");

  investment *= pow(1 + kInterestRate, kYears);

  std::cout << "You will have $" << std::fixed << std::setprecision(2)
  << investment << " in " << kYears << " years\n";
}
