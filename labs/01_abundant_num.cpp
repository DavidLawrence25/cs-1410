/*
	For all the code Rose wrote for CS 1410, visit this Git repository:
	https://github.com/DavidLawrence25/cs-1410
*/

#include <iostream>
#include <string>
#include <math.h>

enum num_t {deficient, perfect, abundant};

// modified from factors_of in https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/int_utils.hpp
int sum_of_factors(const int x) {
	if (x < 1) {
		throw std::invalid_argument("get_factors only accepts strictly-positive integers\n");
	}

	int upper_bound = (int)sqrt(x);
	int sum = 1; // note that x is not included in the sum

	for (int i = 2; i <= upper_bound; i++) {
		div_t division = div(x, i);
		if (division.rem != 0) {
			continue;
		}

		sum += i;
		if (i * i != x) {
			sum += division.quot;
		}
	}

	return sum;
}

// borrowed from https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/user_input.hpp
int get_integer(const std::string prompt, const std::string conversion_failed_message) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		try {
			return stoi(input);
		} catch (const std::invalid_argument& ia) {
			std::cout << conversion_failed_message;
		}
	}
}

num_t determine_number_type(const int x) {
	int sum = sum_of_factors(x);
	if (sum < x) {
		return num_t::deficient;
	}
	if (sum > x) {
		return num_t::abundant;
	}
	return num_t::perfect;
}

int main() {
	std::cout << "Number Types:\n";
	while (true) {
		int x = get_integer("Enter a number (-1 to quit): ", "Invalid input. Please try again.\n");
		if (x == -1) {
			return 0;
		}

		num_t x_type = determine_number_type(x);
		if (x_type == num_t::deficient) {
			std::cout << x << " is a deficient number.\n\n";
		} else if (x_type == num_t::perfect) {
			std::cout << x << " is a perfect number.\n\n";
		} else if (x_type == num_t::abundant) {
			std::cout << x << " is an abundant number.\n\n";
		} else {
			std::cout << "What the frick did you do?\n\n";
		}
	}
	return 0;
}
