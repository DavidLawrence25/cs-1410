#include <math.h>

#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>

#include "custom_libraries/number_utils.h"
#include "custom_libraries/user_input.h"

enum NumberType {
  kDeficient,
  kPerfect,
  kAbundant
};

// Sums the factors of `x`, excluding `x` itself.
// If `x` cannot be factored, returns 1.
int SumOfFactors(int x);
// Returns the number type of `x` based on the sum of its factors.
// See definition for rules on what determines number type.
NumberType NumberTypeOf(int x);

int main() {
  std::cout << "Number Types:\n";

  while (true) {
    int x = rose::GetInteger("Enter a number (-1 to quit): ",
                             "Invalid input. Please try again.\n");
    if (x == -1) return 0;

    switch (NumberTypeOf(x)) {
      case kDeficient:
        std::cout << x << " is a deficient number.\n\n";
        break;
      case kPerfect:
        std::cout << x << " is a perfect number.\n\n";
        break;
      case kAbundant:
        std::cout << x << " is an abundant number.\n\n";
        break;
      default:
        std::cout << "What the frick did you do?\n\n";
    }
  }
}

// Uses `rose::FactorsOf(x)` to retrieve the factors of `x`,
// then calculates the sum of those minus `x`.
int SumOfFactors(int x) {
  const int kSumOperation = 0;
  std::unordered_set<int> factors = rose::FactorsOf(x);
  // Note that `x` is not considered in the sum, so it must be subtracted.
  return std::accumulate(factors.begin(), factors.end(), kSumOperation) - x;
}

// The number type refers to how the sum of `x`'s factors relates to `x`.
NumberType NumberTypeOf(int x) {
  int sum = SumOfFactors(x);
  if (sum < x) {
    return NumberType::kDeficient;
  }
  if (sum > x) {
    return NumberType::kAbundant;
  }
  return NumberType::kPerfect;
}
