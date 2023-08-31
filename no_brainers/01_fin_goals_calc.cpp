#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;

int text_prompt(string prompt, unordered_map<string, int> options) {
	while (true) {
		string option;

		cout << prompt;
		cin >> option;

		if (options.find(option) != options.end()) return options[option];

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

void calculate_years() {
	double investment = text_prompt("Enter Investment Amount: ");
	const double interest_rate = 0.01 * text_prompt("Enter Interest Rate: ");
	const double goal = text_prompt("Enter Financial Goal: ");

	int goal_width = (int)log10(goal) + 4;

	int years = 0;
	while (investment < goal) {
		years++;
		investment += investment * interest_rate;
		cout << "Year " << setw(3) << years << ". " << setw(goal_width)
		<< fixed << setprecision(2) << investment << endl;
	}

	if (years == 1) cout << "That will take 1 year\n";
	else cout << "That will take " << years << " years\n";
}

void calculate_amount() {
	double investment = text_prompt("Enter Investment Amount: ");
	const double interest_rate = 0.01 * text_prompt("Enter Interest Rate: ");
	const int years = (int)text_prompt("Enter Years to Maturity: ");

	investment *= pow(1 + interest_rate, years);

	cout << "You will have " << investment << " in " << years << " years\n";
}

int main() {
	cout << "Financial Goal Calculator\n";

	while (true) {
		int choice = menu();
		if (choice == 1) calculate_years();
		else if (choice == 2) calculate_amount();
		else if (choice == 3) return 0;
	}
}
