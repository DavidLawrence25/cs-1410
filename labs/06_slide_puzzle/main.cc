#include <iostream>
#include <random>

#include "custom_libraries/user_input.h"
#include "puzzle.h"

int main() {
  const int kPuzzleSize = 3;
  std::random_device rd;
  std::mt19937 rng(rd());
  rose::Puzzle puzzle(kPuzzleSize);
  puzzle.Shuffle(rng, 100);

  std::cout << "== " << kPuzzleSize * kPuzzleSize - 1 << "-PUZZLE GAME ==\n";
  while (!puzzle.IsSolved()) {
    std::cout << puzzle.ToString();
    int num_to_move = rose::GetInteger(
        "Choose a number to move: ",
        static_cast<bool (*)(int, rose::Puzzle)>(rose::Puzzle::CanMoveTile),
        "Number must be an integer\n", "That won't work\n", puzzle);
    puzzle.SwapTiles(puzzle.get_position_of(num_to_move),
                     puzzle.get_position_of(0));
  }
  std::cout << puzzle.ToString() << "Good job!\n";
  return 0;
}
