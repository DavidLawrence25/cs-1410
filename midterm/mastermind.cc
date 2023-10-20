#include "mastermind.h"

#include <random>
#include <string>

rose::Mastermind::Mastermind() {
  solution_ = "ROGB";  // Helpful for testing.
  std::random_device rd;
  rng_.seed(rd());
  set_random_colors();
}

int rose::Mastermind::get_colors_correct(std::string guess) {
  int total = 0;
  std::string solution_remainder = solution_;
  std::string guess_remainder = guess;

  // Filter out positional matches.
  for (int i = 0; i < 4; ++i) {
    if (solution_[i] != guess[i]) continue;
    solution_remainder.erase(i, 1);
    guess_remainder.erase(i, 1);
  }

  // Find non-positional matches.
  for (char c : guess_remainder) {
    for (int i = 0; i < solution_remainder.length(); ++i) {
      if (c != solution_remainder[i]) continue;
      ++total;
      solution_remainder.erase(i, 1);
      break;
    }
  }

  return total;
}

int rose::Mastermind::get_positions_correct(std::string guess) {
  int total = 0;

  for (int i = 0; i < 4; ++i) {
    if (solution_[i] == guess[i]) ++total;
  }

  return total;
}

char rose::Mastermind::get_random_letter() {
  std::uniform_int_distribution<int> distribution(0, 4);

  switch (distribution(rng_)) {
    case 0: return 'R';
    case 1: return 'O';
    case 2: return 'Y';
    case 3: return 'G';
    case 4: return 'B';
    default: return 'E';  // E is for ERROR.
  }
}

std::string rose::Mastermind::get_solution() {
  return solution_;
}

void rose::Mastermind::set_random_colors() {
  solution_ = "";
  for (int i = 0; i < 4; ++i) solution_ += get_random_letter();
}

void rose::Mastermind::set_solution(std::string solution) {
  solution_ = solution;
}
