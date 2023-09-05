#include <iostream>
#include <string>
#include <math.h>
using namespace std;

enum number_type {deficient, perfect, abundant};

int sum_of_factors(int x) {
	if (x < 1) throw invalid_argument("get_factors only accepts strictly-positive integers\n");

	int upper_bound = (int)sqrt(x);
	int sum = 1; // note that x is not included in the sum

	for (int i = 2; i <= upper_bound; i++) {
		div_t division = div(x, i);
		if (division.rem) continue; // if i isn't a factor of x, continue
		sum += i;
		if (i * i != x) {
			sum += division.quot;
		}
	}

	return sum;
}

number_type determine_number_type(int x) {
	int sum = sum_of_factors(x);
	if (sum < x) return number_type::deficient;
	if (sum > x) return number_type::abundant;
	return number_type::perfect;
}

int get_number() {
	while (true) {
		string input;

		cout << "Enter a number (-1 to quit): ";
		cin >> input;

		try {
			return stoi(input);
		} catch (const invalid_argument& ia) {
			cout << "Invalid input. Please try again.\n";
		}
	}
}

int main() {
	cout << "Number Types:\n";
	while (true) {
		int x = get_number();
		if (x == -1) return 0;

		number_type x_type = determine_number_type(x);
		if (x_type == number_type::deficient) {
			cout << x << " is a deficient number.\n\n";
		} else if (x_type == number_type::perfect) {
			cout << x << " is a perfect number.\n\n";
		} else if (x_type == number_type::abundant) {
			cout << x << " is an abundant number.\n\n";
		} else {
			cout << "What the frick did you do?\n\n";
		}
	}
	return 0;
}
