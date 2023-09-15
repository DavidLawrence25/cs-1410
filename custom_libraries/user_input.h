#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "custom_libraries/number_utils.h"

#ifndef CS1410_CUSTOMLIBRARIES_USERINPUT_H_
#define CS1410_CUSTOMLIBRARIES_USERINPUT_H_

namespace rose {

// A set of various string representations of the number 0. Used several times
// throughout the file, especially in functions that need to check whether or
// not the number was valid.
const std::unordered_set<std::string> kZeros =
    {"0", "0.", "0.0", "0.00", "0.000", "0.0000", "0.00000", "0.000000",
     "0.0000000", "0.00000000", "0.000000000", "0.0000000000", "0.00000000000",
     "0.000000000000", "0.0000000000000", "0.00000000000000",
     "0.000000000000000", "+0", "+0.", "+0.0", "+0.00", "+0.000", "+0.0000",
     "+0.00000", "+0.000000", "+0.0000000", "+0.00000000", "+0.000000000",
     "+0.0000000000", "+0.00000000000", "+0.000000000000", "+0.0000000000000",
     "+0.00000000000000", "+0.000000000000000", "-0", "-0.", "-0.0", "-0.00",
     "-0.000", "-0.0000", "-0.00000", "-0.000000", "-0.0000000", "-0.00000000",
     "-0.000000000", "-0.0000000000", "-0.00000000000", "-0.000000000000",
     "-0.0000000000000", "-0.00000000000000", "-0.000000000000000",};

// Returns a number based on the option the end user picked. Loops until the
// user's input is one from the options provided.
int MenuPrompt(std::string prompt, std::string option_not_found_message,
               std::unordered_map<std::string, int> options) {
  while (true) {
    std::string option;

    std::cout << prompt;
    std::cin >> option;

    if (options.find(option) != options.end()) return options.at(option);

    std::cout << option_not_found_message;
  }
}

// Gets an integer from the user and returns it. Loops until the user's input is
// a proper integer.
int GetInteger(std::string prompt, std::string conversion_failed_message) {
  while (true) {
    std::string input;

    std::cout << prompt;
    std::cin >> input;

    int x = rose::StringToInt(input);
    if (x != 0 || kZeros.find(input) != kZeros.end()) return x;
    std::cout << conversion_failed_message;
  }
}

// Gets an integer from the user and returns it. Loops until the user's input is
// a proper integer that satisfies the validator function.
template <typename... ExtraArgs>
int GetInteger(std::string prompt, bool (*validator)(int, ExtraArgs...),
               std::string conversion_failed_message,
               std::string validator_failed_message, ExtraArgs... extra_args) {
  while (true) {
    std::string input;

    std::cout << prompt;
    std::cin >> input;

    int x = rose::StringToInt(input);
    if (x == 0 && kZeros.find(input) == kZeros.end()) {
      std::cout << conversion_failed_message;
      continue;
    }

    if (validator(x, extra_args...)) return x;
    std::cout << validator_failed_message;
  }
}

// Gets a double from the user and returns it. Loops until the user's input is
// a proper double.
double GetDouble(std::string prompt, std::string conversion_failed_message) {
  while (true) {
    std::string input;

    std::cout << prompt;
    std::cin >> input;

    double x = rose::StringToDouble(input);
    if (x != 0.0 || kZeros.find(input) != kZeros.end()) return x;
    std::cout << conversion_failed_message;
  }
}

// Gets a double from the user and returns it. Loops until the user's input is
// a proper double that satisfies the validator function.
template <typename... ExtraArgs>
double GetDouble(std::string prompt, bool (*validator)(double, ExtraArgs...),
                 std::string conversion_failed_message,
                 std::string validator_failed_message,
                 ExtraArgs... extra_args) {
  while (true) {
    std::string input;

    std::cout << prompt;
    std::cin >> input;

    double x = rose::StringToDouble(input);
    if (x == 0.0 && kZeros.find(input) == kZeros.end()) {
      std::cout << conversion_failed_message;
      continue;
    }

    if (validator(x, extra_args...)) return x;
    std::cout << validator_failed_message;
  }
}

}  // namespace rose

#endif  // CS1410_CUSTOMLIBRARIES_USERINPUT_H_
