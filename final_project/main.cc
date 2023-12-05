#include <iostream>
#include <unordered_map>

#include "board.h"
#include "custom_libraries/number_utils.h"
#include "dictionary_reader.h"

// Maps the word length to the allowed number of guesses.
const std::unordered_map<size_t, size_t> kLengthToGuesses = {
    {4, 7}, {5, 6}, {6, 5}};
// Maps the word length to the solution dictionary's file path.
const std::unordered_map<size_t, std::string> kLengthToDictPath = {
    {4, "final_project/four_solutions.txt"},
    {5, "final_project/five_solutions.txt"},
    {6, "final_project/six_solutions.txt"}};
// Maps the word length to the length of the corresponding solution dictionary.
const std::unordered_map<size_t, size_t> kLengthToDictLength = {
    {4, 2365}, {5, 3927}, {6, 5977}};

int main(int argc, char *argv[]) {
  // Print the usage message if there aren't exactly two arguments.
  if (argc != 2) {
    std::cout << "Usage: ./final_project/main.exe <word_length>\n";
    return 0;
  }
  // Throw an error if the word length is not an integer.
  size_t word_length = rose::StringToInt(argv[1]);
  if (word_length == 0 && !rose::IsZero(argv[1])) {
    std::cout << "[ERROR] Word length must be an integer.\n";
    return 0;
  }
  // Throw an error if the word length is outside the allowed range.
  if (word_length < 4 || word_length > 6) {
    std::cout << "[ERROR] Word length must be on the interval [4, 6].\n";
    return 0;
  }

  std::random_device rd;
  std::mt19937 rng(rd());

  rose::Board board(
      word_length, kLengthToGuesses.at(word_length),
      {kLengthToDictPath.at(word_length), kLengthToDictLength.at(word_length)});
  board.SetRandomSolution(rng);

  board.DisplayGame();
  for (size_t i = 0; i < board.num_of_guesses(); ++i) {
    board.ReadWord(i);
    if (board.is_solved()) {
      std::cout << "Congrats!\n";
      return 0;
    }
  }

  std::cout << "Sorry, the solution was " << board.solution() << ".\n";
  return 0;
}
