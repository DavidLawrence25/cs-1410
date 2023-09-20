#include <time.h>

#include <iostream>
#include <random>
#include <string>

#include "custom_libraries/user_input.h"

enum TurnType {
  kHuman,
  kRobot
};

// Returns true if `n` stones can be taken from the pile.
bool can_take_stones(int n, int pile_size);
// Returns the number of stones left in the pile after the human took them.
// Note that this function does not remove any stones on its own.
int take_stones_human(int pile_size);
// Returns the number of stones left in the pile after the robot took them.
// Note that this function does not remove any stones on its own.
int take_stones_robot(int pile_size, std::mt19937 &rng);

int main() {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> starting_pile_distribution(10, 30);

  int pile_size = starting_pile_distribution(rng);
  TurnType turn = TurnType::kHuman;

  while (pile_size > 0) {
    switch (turn) {
      case kHuman:
        std::cout << "Stones in The Pile: " << pile_size << '\n';
        pile_size = take_stones_human(pile_size);
        turn = TurnType::kRobot;
        break;
      case kRobot:
        pile_size = take_stones_robot(pile_size, rng);
        turn = TurnType::kHuman;
        break;
      default:
        std::cout << "What the frick did you do?\n";
    }
  }

  switch (turn) {
    case kHuman:
      std::cout << "You win!\n";
      break;
    case kRobot:
      std::cout << "\nYou lose.\n";
      break;
    default:
      std::cout << "What the frick did you do?\n";
  }

  return 0;
}

// Returns true when `n` is inside the range appropriate for `pile_size`:
// `3 < pile_size ------> 0 < n <= 3`
// `1 < pile_size <= 3 -> 0 < n < pile_size`
// `pile_size == 1 -----> n == 1`
bool can_take_stones(int n, int pile_size) {
  int max_stones_to_take = pile_size > 3 ? 4 : pile_size;  // Exclusive bound.
  return n > 0 && (n < max_stones_to_take || (n == pile_size == 1));
}

// Returns the number of stones left in the pile after the human took them.
int take_stones_human(int pile_size) {
  int stones_to_take = rose::GetInteger(
      "How many will you take? ", &can_take_stones, "That's not an integer\n",
      "Invalid amount\n", pile_size);
  return pile_size - stones_to_take;
}

// Returns the number of stones left in the pile after the robot took them.
// The caller must supply a random number generator `std::mt19937`.
int take_stones_robot(int pile_size, std::mt19937& rng) {
  int stones_to_take;
  if (pile_size <= 2) {
    stones_to_take = 1;
  } else if (pile_size == 3) {
    stones_to_take = 2;
  } else if (pile_size == 4) {
    stones_to_take = 3;
  } else {
    std::uniform_int_distribution<int> stone_distribution(1, 3);
    stones_to_take = stone_distribution(rng);
  }

  std::cout << "Computer takes " << stones_to_take << "\n\n";
  return pile_size - stones_to_take;
}
