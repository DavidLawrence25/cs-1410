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

template <typename... ExtraArgs>
float get_float(const std::string prompt, bool (*validator)(float, ExtraArgs...), const std::string conversion_failed_message, const std::string validator_failed_message, ExtraArgs... extra_args) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		float x;
		try {
			x = stof(input);
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

template <typename... ExtraArgs>
double get_double(const std::string prompt, bool (*validator)(double, ExtraArgs...), const std::string conversion_failed_message, const std::string validator_failed_message, ExtraArgs... extra_args) {
	while (true) {
		std::string input;

		std::cout << prompt;
		std::cin >> input;

		double x;
		try {
			x = stod(input);
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
