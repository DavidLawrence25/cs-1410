#include "board.h"

#include <conio.h>

#include <iostream>
#include <sstream>

#include "drawing.h"

namespace rose {

Board::Board(size_t word_length, size_t num_of_guesses, Dictionary dict) {
  word_length_ = word_length;
  num_of_guesses_ = num_of_guesses;
  is_solved_ = false;
  dict_ = dict;
  keyboard_ = KeyboardDisplay();

  for (size_t i = 0; i < num_of_guesses; ++i) {
    guesses_.push_back(std::string(word_length_, ' '));
  }
}

void Board::SetRandomSolution(std::mt19937 &rng) {
  DictionaryReader reader;
  solution_ = reader.GetRandomSolution(dict_, rng);
}

void Board::ReadWord(size_t guess_index) {
  DictionaryReader reader;
  std::string *this_word = &guesses_[guess_index];
  size_t chars_entered = 0;
  bool processing = true;

  while (processing) {
    char this_char = getch();

    if (this_char == '\b') {
      if (chars_entered == 0) continue;
      this_word->at(chars_entered - 1) = ' ';
      --chars_entered;
      DisplayGame();
      continue;
    }

    if (chars_entered == word_length_) {
      processing = !(this_char == '\n' || this_char == '\r');
      if (!processing && !reader.IsLegal(*this_word)) {
        DisplayGame();
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

    DisplayGame();
  }

  is_solved_ = (*this_word == solution_);
  keyboard_.UpdateMap(*this_word, GenerateColorMap(*this_word));
  ColorizeWord(this_word);
  DisplayGame();
}

std::vector<Color> Board::GenerateColorMap(std::string word) {
  std::string correct = solution_;
  std::vector<Color> color_map;

  // Populate the color map.
  for (size_t i = 0; i < word_length_; ++i) color_map.push_back(kGray);

  // Find exact matches (letters to color green).
  size_t exact_matches = 0;
  for (size_t i = 0; i < word_length_; ++i) {
    if (word[i] != solution_[i]) continue;
    correct.erase(i - exact_matches, 1);
    ++exact_matches;
    color_map[i] = kGreen;
  }

  // Find inexact matches (letters to color yellow).
  for (size_t i = 0; i < word_length_; ++i) {
    if (color_map[i] == kGreen) continue;
    for (size_t j = 0; j < correct.length(); ++j) {
      if (word[i] != correct[j]) continue;
      correct.erase(j, 1);
      color_map[i] = kYellow;
      break;
    }
  }

  return color_map;
}

void Board::ColorizeWord(std::string *word) {
  std::vector<Color> color_map = GenerateColorMap(*word);

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

void Board::DisplayGame() {
  const size_t kTotalLines = __max(kKeyboardHeight, num_of_guesses_ + 2);

  system("cls");  // Clears the terminal.
  std::cout << "WORDLE\n";

  for (size_t i = 0; i < kTotalLines; ++i) {
    if (i < (num_of_guesses_ + 3)) {
      Display(i);
    } else {
      std::cout << std::string(word_length_ + 2, ' ');
    }

    std::cout << "  ";
    keyboard_.Display(i);
    std::cout << '\n';
  }
}

void Board::Display(size_t line) {
  if (line == 0) {
    std::cout << kUpLeft << std::string(word_length_, kHori) << kUpRight;
  } else if (line < (num_of_guesses_ + 1)) {
    std::cout << kVert << guesses_[line - 1] << kVert;
  } else if (line == (num_of_guesses_ + 1)) {
    std::cout << kDownLeft << std::string(word_length_, kHori) << kDownRight;
  }
}

}  // namespace rose
