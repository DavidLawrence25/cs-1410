#include <iostream>

#include "board.h"

// \033[0m\xC9\xCD\xCD\xCD\xCD\xCD\xBB\n
// \xBAWE\033[32mA\033[0mRY\xBA\n
// \xBAC\033[33mO\033[0mU\033[32mN\033[0mT\xBA\n
// \xBAS\033[33mPI\033[0mLL\xBA\n
// \xBA\033[32mPIANO\033[0m\xBA\n
// \xBA     \xBA\n
// \xBA     \xBA\n
// \xC8\xCD\xCD\xCD\xCD\xCD\xBC\n

int main() {
  rose::Board board(/*word_length=*/5, /*num_of_guesses=*/6, /*list_path=*/"");
  board.SetSolution("PIANO");

  board.Display();
  for (size_t i = 0; i < board.num_of_guesses(); ++i) {
    board.ReadWord(i);
    if (board.is_solved()) {
      std::cout << "Congrats!\n";
      break;
    }
  }

  return 0;
}
