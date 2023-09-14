/*
	For all the code Rose wrote for CS 1410, visit this Git repository:
	https://github.com/DavidLawrence25/cs-1410
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <unordered_map>

int menu_prompt(const std::string prompt, const std::string option_not_found_message, const std::unordered_map<std::string, int> options); // user_input.hpp
double get_double(const std::string prompt, const std::string conversion_failed_message); // user_input.hpp
int menu();
void calculate_years();
void calculate_amount();

int main() {
	std::cout << "Financial Goal Calculator\n";

	while (true) {
		int choice = menu();
		if (choice == 1) {
			calculate_years();
		} else if (choice == 2) {
			calculate_amount();
		} else if (choice == 3) {
			return 0;
		}
	}
}

// borrowed from https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/user_input.hpp
int menu_prompt(const std::string prompt, const std::string option_not_found_message, const std::unordered_map<std::string, int> options) {
	while (true) {
		std::string option;

		std::cout << prompt;
		std::cin >> option;

		if (options.find(option) != options.end()) {
			return options.at(option);
		}

		std::cout << option_not_found_message;
	}
}

// borrowed from https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/user_input.hpp
double get_double(const std::string prompt, const std::string conversion_failed_message) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		try {
			return stod(input);
		} catch (const std::invalid_argument& ia) {
			std::cout << conversion_failed_message;
		}
	}
}

int menu() {
	const std::unordered_map<std::string, int> options {{"1", 1}, {"2", 2}, {"3", 3}};

	return menu_prompt(
		"1. Calculate Years to Financial Goal\n2. Calculate Amount Based on Years\n3. Quit\n",
		"Invalid input. Please try again\n",
		options
	);
}

void calculate_years() {
	double investment = get_double("Enter Investment Amount: ", "Invalid input. Please try again\n");
	const double interest_rate = 0.01 * get_double("Enter Interest Rate: ", "Invalid input. Please try again\n");
	const double goal = get_double("Enter Financial Goal: ", "Invalid input. Please try again\n");

	const int goal_width = (int)log10(goal) + 4;

	int years = 0;
	while (investment < goal) {
		years++;
		investment += investment * interest_rate;
		std::cout << "Year " << std::setw(3) << years << ". " << std::setw(goal_width)
		<< std::fixed << std::setprecision(2) << investment << '\n';
	}

	if (years == 1) {
		std::cout << "That will take 1 year\n";
	} else {
		std::cout << "That will take " << years << " years\n";
	}
}

void calculate_amount() {
	double investment = get_double("Enter Investment Amount: ", "Invalid input. Please try again\n");
	const double interest_rate = 0.01 * get_double("Enter Interest Rate: ", "Invalid input. Please try again\n");
	const int years = (int)get_double("Enter Years to Maturity: ", "Invalid input. Please try again\n");

	investment *= pow(1 + interest_rate, years);

	std::cout << "You will have " << investment << " in " << years << " years\n";
}
