#include <stdlib.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "dictionary_reader.h"
#include "keyboard_display.h"

#ifndef CS1410_FINALPROJECT_BOARD_H_
#define CS1410_FINALPROJECT_BOARD_H_

namespace rose {

// Represents a game of Wordle.
class Board {
 public:
  Board(size_t word_length, size_t num_of_guesses, Dictionary dict);

  std::string solution() { return solution_; }
  size_t word_length() { return word_length_; }
  size_t num_of_guesses() { return num_of_guesses_; }
  bool is_solved() { return is_solved_; }

  // Sets the solution to `word`.
  void SetSolution(std::string word) { solution_ = word; }
  // Sets the solution to a random word from the solution dictionary.
  void SetRandomSolution(std::mt19937 &rng);
  // Reads in a word from the user and writes it to the guesses vector.
  void ReadWord(size_t guess_index);
  // Returns a vector of colors corresponding to the correctness of `word`.
  std::vector<Color> GenerateColorMap(std::string word);
  // Adds ANSI color sequences to `word` to communicate correctness.
  void ColorizeWord(std::string *word);
  // Displays both the board and the keyboard to the terminal.
  void DisplayGame();
  // Displays a single line of the board, not including the keyboard.
  void Display(size_t line);

 private:
  // The correct word.
  std::string solution_;
  // The number of letters in each word.
  size_t word_length_;
  // The number of guesses the player is allowed to make.
  size_t num_of_guesses_;
  // Self-explanatory.
  bool is_solved_;
  // A list of guesses made by the player.
  std::vector<std::string> guesses_;
  // The solution dictionary.
  Dictionary dict_;
  // The keyboard shown on screen with certain keys colored to show correctness.
  KeyboardDisplay keyboard_;
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_BOARD_H_
