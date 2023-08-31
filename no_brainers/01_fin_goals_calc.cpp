#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
using namespace std;

int text_prompt(string prompt, unordered_map<string, int> options) {
	while (true) {
		string option;

		cout << prompt;
		cin >> option;

		if (options.find(option) == options.end()) return options[option];

		cout << "Invalid input. Please try again.\n";
	}
}

double text_prompt(string prompt) {
	while (true) {
		string input;

		cout << prompt;
		cin >> input;

		try {
			return stod(input);
		} catch (const invalid_argument& ia) {
			cout << "Invalid input. Please try again.\n";
		}
	}
}

int menu() {
	unordered_map<string, int> options;
	options["1"] = 1;
	options["2"] = 2;
	options["3"] = 3;

	return text_prompt(
		"1. Calculate Years to Financial Goal\n2. Calculate Amount Based on Years\n3. Quit\n",
		options
	);
}

int calculate_years() {
	double investment = text_prompt("Enter Investment Amount: ");
	const double interest_rate = text_prompt("Enter Interest Rate: ");
	const double goal = text_prompt("Enter Financial Goal: ");

	int years;
	while (investment < goal) {
		years++;
		investment += investment * interest_rate;
		cout << "Year " << setw(3) << years << ". "; // set width based on the goal
	}
}

int main() {

	return 0;
}
