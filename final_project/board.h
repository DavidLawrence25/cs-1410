#include <stdlib.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "dictionary_reader.h"
#include "keyboard_display.h"

#ifndef CS1410_FINALPROJECT_BOARD_H_
#define CS1410_FINALPROJECT_BOARD_H_

namespace rose {

class Board {
 public:
  Board(size_t word_length, size_t num_of_guesses, Dictionary dict);

  std::string solution() { return solution_; }
  size_t word_length() { return word_length_; }
  size_t num_of_guesses() { return num_of_guesses_; }
  bool is_solved() { return is_solved_; }

  void SetSolution(std::string word) { solution_ = word; }
  void SetRandomSolution(std::mt19937 &rng);
  void ReadWord(size_t guess_index);
  std::vector<Color> GenerateColorMap(std::string word);
  void ColorizeWord(std::string *word);
  void DisplayGame();
  void Display(size_t line);

 private:
  std::string solution_;
  size_t word_length_;
  size_t num_of_guesses_;
  bool is_solved_;
  std::vector<std::string> guesses_;
  Dictionary dict_;
  KeyboardDisplay keyboard_;
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_BOARD_H_
