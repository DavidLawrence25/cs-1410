#include <iostream>

#include "board.h"
#include "dictionary_reader.h"

int main() {
  std::random_device rd;
  std::mt19937 rng(rd());

  rose::Board board(/*word_length=*/5, /*num_of_guesses=*/6,
                    /*dict=*/{"final_project/five_solutions.txt", 3927});
  board.SetRandomSolution(rng);

  board.Display();
  for (size_t i = 0; i < board.num_of_guesses(); ++i) {
    board.ReadWord(i);
    if (board.is_solved()) {
      std::cout << "Congrats!\n";
      return 0;
    }
  }

  std::cout << "Sorry, the solution was " << board.solution() << '\n';
  return 0;
}
