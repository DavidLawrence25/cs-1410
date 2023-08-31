#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double get_income(int year) {
	while (true) {
		string income;

		cout << "Enter income for " << year << ": ";
		cin >> income;

		try {
			return stod(income);
		}
		catch (const invalid_argument& ia) {
			cout << "Input must be a number\n";
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

	cout << "Income (averaged over the past " << years << " years) is: $"
	<< fixed << setprecision(2) << average_income;

	return 0;
}
