#include <iostream>
#include <unordered_set>
#include <math.h>

std::unordered_set<int> factors_of(int x) {
	if (x < 1) {
		throw std::invalid_argument("Only strictly-positive numbers can be factored.\n");
	}
	if (x == 1) {
		return std::unordered_set<int> {1};
	}

	const int upper_bound = (int)sqrt(x);
	std::unordered_set<int> factors = {1, x};

	for (int i = 2; i <= upper_bound; i++) {
		div_t division = div(x, i);
		if (division.rem == 0) {
			factors.insert(i);
			factors.insert(division.quot);
		}
	}

	return factors;
}

bool is_prime(int x) {
	if (x < 1) {
		throw std::invalid_argument("Only strictly-positive numbers can be assigned primality.\n");
	}
	if (x == 1) {
		return false;
	}

	const int upper_bound = (int)sqrt(x);

	for (int i = 2; i <= upper_bound; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}
