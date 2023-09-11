/*
	For all the code Rose wrote for CS 1410, visit this Git repository:
	https://github.com/DavidLawrence25/cs-1410
*/

#include <iostream>
#include <iomanip>
#include <string>

double get_income(const int year); // user_input.hpp (modified)

int main() {
	const int YEARS = 5;
	const int START_YEAR = 2016;

	double total_income = 0.0;
	for (int i = 0; i < YEARS; i++) {
		total_income += get_income(START_YEAR - i);
	}

	double average_income = total_income / YEARS;

	std::cout << "Income (averaged over the past " << YEARS << " years) is: $"
	<< std::fixed << std::setprecision(2) << average_income;

	return 0;
}

// modified from get_double in https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/user_input.hpp
double get_income(const int year) {
	while (true) {
		std::string income;

		std::cout << "Enter income for " << year << ": ";
		std::cin >> income;

		try {
			return stod(income);
		} catch (const std::invalid_argument& ia) {
			std::cout << "Input must be a number\n";
		}
	}
}