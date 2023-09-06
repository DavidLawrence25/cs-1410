#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <unordered_map>

int text_prompt(const std::string prompt, const std::unordered_map<std::string, int> options) {
	while (true) {
		std::string option;

		std::cout << prompt;
		std::cin >> option;

		if (options.find(option) != options.end()) {
			return options.at(option);
		}

		std::cout << "Invalid input. Please try again.\n";
	}
}

double text_prompt(const std::string prompt) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		try {
			return stod(input);
		} catch (const std::invalid_argument& ia) {
			std::cout << "Invalid input. Please try again.\n";
		}
	}
}

int menu() {
	const std::unordered_map<std::string, int> options {{"1", 1}, {"2", 2}, {"3", 3}};

	return text_prompt(
		"1. Calculate Years to Financial Goal\n2. Calculate Amount Based on Years\n3. Quit\n",
		options
	);
}

void calculate_years() {
	double investment = text_prompt("Enter Investment Amount: ");
	const double interest_rate = 0.01 * text_prompt("Enter Interest Rate: ");
	const double goal = text_prompt("Enter Financial Goal: ");

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
	double investment = text_prompt("Enter Investment Amount: ");
	const double interest_rate = 0.01 * text_prompt("Enter Interest Rate: ");
	const int years = (int)text_prompt("Enter Years to Maturity: ");

	investment *= pow(1 + interest_rate, years);

	std::cout << "You will have " << investment << " in " << years << " years\n";
}

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
