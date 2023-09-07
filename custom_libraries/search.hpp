#include <vector>

// returns the index of the value in the sorted vector, if present (returns -1 otherwise)
int binary_search(const std::vector<int> numbers, const int value) {
	int left_bound = 0;
	int right_bound = numbers.size() - 1;

	while (left_bound <= right_bound) {
		int middle_index = (left_bound + right_bound) >> 1;
		if (numbers.at(middle_index) < value) {
			left_bound = middle_index + 1;
		} else if (numbers.at(middle_index) > value) {
			right_bound = middle_index - 1;
		} else {
			return middle_index;
		}
	}

	return -1;
}
