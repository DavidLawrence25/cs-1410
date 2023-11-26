#include "board.h"

#include <conio.h>

#include <iostream>
#include <sstream>

namespace rose {

enum Color { kWhite, kGray, kYellow, kGreen };
const std::unordered_map<Color, std::string> kColorStrings = {
    {kWhite, "\033[0m"},
    {kGray, "\033[38;5;248m"},
    {kYellow, "\033[33m"},
    {kGreen, "\033[32m"}};

Board::Board(size_t word_length, size_t num_of_guesses, Dictionary dict) {
  word_length_ = word_length;
  num_of_guesses_ = num_of_guesses;
  is_solved_ = false;
  dict_ = dict;

  for (size_t i = 0; i < num_of_guesses; ++i) {
    guesses_.push_back(std::string(word_length_, ' '));
  }
}

void Board::SetRandomSolution(std::mt19937 &rng) {
  DictionaryReader reader;
  solution_ = reader.GetRandomSolution(dict_, rng);
}

void Board::ReadWord(size_t guess_index) {
  static const int kBackspace = 8;
  DictionaryReader reader;
  std::string *this_word = &guesses_[guess_index];
  size_t chars_entered = 0;
  bool processing = true;

  while (processing) {
    char this_char = getch();

    if (this_char == kBackspace) {
      if (chars_entered == 0) continue;
      this_word->at(chars_entered - 1) = ' ';
      --chars_entered;
      Display();
      continue;
    }

    if (chars_entered == word_length_) {
      processing = !(this_char == '\n' || this_char == '\r');
      if (!processing && !reader.IsLegal(*this_word)) {
        Display();
        std::cout << "Not in word list\n";
        processing = true;
      }
      continue;
    }

    if (this_char >= 'A' && this_char <= 'Z') {
      this_word->at(chars_entered) = this_char;
      ++chars_entered;
    } else if (this_char >= 'a' && this_char <= 'z') {
      // In ASCII, lowercase letters are offset from uppercase letters by 32.
      this_word->at(chars_entered) = this_char - 32;
      ++chars_entered;
    } else {
      continue;
    }

    Display();
  }

  is_solved_ = (*this_word == solution_);
  ColorizeWord(this_word);
  Display();
}

void Board::ColorizeWord(std::string *word) {
  std::string correct = solution_;
  Color color_map[word_length_];

  // Populate the color map.
  for (size_t i = 0; i < word_length_; ++i) color_map[i] = kGray;

  // Find exact matches (letters to color green).
  size_t exact_matches = 0;
  for (size_t i = 0; i < word_length_; ++i) {
    if (word->at(i) != solution_[i]) continue;
    correct.erase(i - exact_matches, 1);
    ++exact_matches;
    color_map[i] = kGreen;
  }

  // Find inexact matches (letters to color yellow).
  for (size_t i = 0; i < word_length_; ++i) {
    if (color_map[i] == kGreen) continue;
    for (size_t j = 0; j < correct.length(); ++j) {
      if (word->at(i) != correct[j]) continue;
      correct.erase(j, 1);
      color_map[i] = kYellow;
      break;
    }
  }

  // Generate a colored string.
  std::stringstream result;
  Color previous = kWhite;
  for (size_t i = 0; i < word_length_; ++i) {
    if (color_map[i] != previous) {
      result << kColorStrings.at(color_map[i]);
      previous = color_map[i];
    }
    result << word->at(i);
  }

  if (previous != kWhite) result << kColorStrings.at(kWhite);
  *word = result.str();
}

void Board::Display() {
  static const char kUpLeft = '\xC9';
  static const char kUpRight = '\xBB';
  static const char kDownLeft = '\xC8';
  static const char kDownRight = '\xBC';
  static const char kHorizontal = '\xCD';
  static const char kVertical = '\xBA';

  system("cls");  // Clears the terminal.

  std::cout << "WORDLE\n";
  std::cout << kUpLeft << std::string(word_length_, kHorizontal) << kUpRight
            << '\n';
  for (std::string guess : guesses_) {
    std::cout << kVertical << guess << kVertical << '\n';
  }
  std::cout << kDownLeft << std::string(word_length_, kHorizontal) << kDownRight
            << '\n';
}

}  // namespace rose
