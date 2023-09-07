#include <iostream>
#include <string>
#include <unordered_map>

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

int get_integer(const std::string prompt, const std::string conversion_failed_message) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		try {
			return stoi(input);
		} catch (const std::invalid_argument& ia) {
			std::cout << conversion_failed_message;
		}
	}
}

float get_float(const std::string prompt, const std::string conversion_failed_message) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		try {
			return stof(input);
		} catch (const std::invalid_argument& ia) {
			std::cout << conversion_failed_message;
		}
	}
}

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
