/*
	For all the code Rose wrote for CS 1410, visit this Git repository:
	https://github.com/DavidLawrence25/cs-1410
*/

#include <iostream>
#include <iomanip>
#include <string>

// unfortunately, this could not reuse anything inside user_input.hpp
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

int main() {
	const int years = 5;
	const int start_year = 2016;

	double total_income = 0.0;
	for (int i = 0; i < years; i++) {
		total_income += get_income(start_year - i);
	}

	double average_income = total_income / years;

	std::cout << "Income (averaged over the past " << years << " years) is: $"
	<< std::fixed << std::setprecision(2) << average_income;

	return 0;
}
