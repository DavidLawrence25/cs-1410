#include <stdlib.h>

#include <string>
#include <unordered_map>
#include <vector>

#ifndef CS1410_FINALPROJECT_BOARD_H_
#define CS1410_FINALPROJECT_BOARD_H_

namespace rose {

class Board {
 public:
  Board(size_t word_length, size_t num_of_guesses, std::string list_path);

  std::string solution() { return solution_; }
  size_t word_length() { return word_length_; }
  size_t num_of_guesses() { return num_of_guesses_; }
  bool is_solved() { return is_solved_; }

  void SetSolution(std::string word) { solution_ = word; }
  void SetRandomSolution();  // TODO: Implement this.
  void ReadWord(size_t guess_index);
  void ColorizeWord(std::string *word);
  void Display();

 private:
  std::string solution_;
  size_t word_length_;
  size_t num_of_guesses_;
  bool is_solved_;
  std::vector<std::string> guesses_;
  std::string list_path_;
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_BOARD_H_
