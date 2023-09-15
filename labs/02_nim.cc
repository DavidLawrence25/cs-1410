#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

enum TurnType {human, robot};

template <typename... ExtraArgs>
int get_integer(const std::string prompt, bool (*validator)(int, ExtraArgs...), const std::string conversion_failed_message, const std::string validator_failed_message, ExtraArgs... extra_args); // user_input.hpp
bool can_take_stones(int n, int pile_size);
int take_stones_human(int pile_size);
int take_stones_robot(int pile_size);

int main() {
	srand(time(NULL)); // initialize the pseudo-random number generator

	const int MIN_STARTING_PILE_SIZE = 10; // inclusive
	const int MAX_STARTING_PILE_SIZE = 100; // exclusive
	int pile_size = rand() % (MAX_STARTING_PILE_SIZE - MIN_STARTING_PILE_SIZE) + MIN_STARTING_PILE_SIZE;
	TurnType turn = TurnType::human;

	while (pile_size > 0) {
		if (turn == TurnType::human) {
			std::cout << "Stones in The Pile: " << pile_size << '\n';
			pile_size = take_stones_human(pile_size);
			turn = TurnType::robot;
		} else if (turn == TurnType::robot) {
			pile_size = take_stones_robot(pile_size);
			turn = TurnType::human;
		} else {
			std::cout << "What the frick did you do?\n";
		}
	}

	if (turn == robot) { // the robot won
		std::cout << "\nYou lose.\n";
	} else if (turn == human) { // the human won
		std::cout << "You win!\n";
	} else {
		std::cout << "What the frick did you do?\n";
	}

	return 0;
}

// borrowed from https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/user_input.hpp
template <typename... ExtraArgs>
int get_integer(const std::string prompt, bool (*validator)(int, ExtraArgs...), const std::string conversion_failed_message, const std::string validator_failed_message, ExtraArgs... extra_args) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		int x;
		try {
			x = stoi(input);
		} catch (const std::invalid_argument& ia) {
			std::cout << conversion_failed_message;
			continue;
		}
		if (validator(x, extra_args...)) {
			return x;
		}

		std::cout << validator_failed_message;
	}
}

bool can_take_stones(int n, int pile_size) {
	int max_stones_to_take = pile_size > 3 ? 4 : pile_size;
	return n > 0 && (n < max_stones_to_take || (n == pile_size == 1));
}

int take_stones_human(int pile_size) {
	return pile_size - get_integer("How many will you take? ", &can_take_stones, "That's not an integer\n", "Invalid amount\n", pile_size);
}

int take_stones_robot(int pile_size) {
	int stones_to_take;
	if (pile_size <= 2) {
		stones_to_take = 1;
	} else if (pile_size == 3) {
		stones_to_take = 2;
	} else if (pile_size == 4) {
		stones_to_take = 3;
	} else {
		stones_to_take = rand() % 3 + 1;
	}

	std::cout << "Computer takes " << stones_to_take << "\n\n";
	return pile_size - stones_to_take;
}
