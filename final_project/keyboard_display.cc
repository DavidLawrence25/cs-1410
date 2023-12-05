#include "keyboard_display.h"

#include <iostream>

namespace rose {

KeyboardDisplay::KeyboardDisplay() {
  for (char letter : "QWERTYUIOPASDFGHJKLZXCVBNM") color_map_[letter] = kWhite;
}

void KeyboardDisplay::UpdateMap(std::string word,
                                std::vector<Color> word_colors) {
  for (size_t i = 0; i < word.length(); ++i) {
    char letter = word[i];
    Color color = word_colors[i];
    // If the color in the keyboard's map is less valuable than the letter's
    // color, set the corresponding color in the keyboard's map to that.
    if (color_map_[letter] < color) color_map_[letter] = color;
  }
}

void KeyboardDisplay::Display(size_t line) {
  if (line == 0) {
    std::cout << kUpLeft << std::string(10, kHori) << kUpRight;
  } else if (line == 1) {
    std::cout << kVert;
    for (char letter : kTopRow) {
      std::cout << kColorStrings.at(color_map_.at(letter)) << letter;
    }
    std::cout << kColorStrings.at(kWhite) << kVert;
  } else if (line == 2) {
    std::cout << kVert;
    for (char letter : kHomeRow) {
      std::cout << kColorStrings.at(color_map_.at(letter)) << letter;
    }
    std::cout << kColorStrings.at(kWhite) << kUpLeft << kDownRight;
  } else if (line == 3) {
    std::cout << kDownLeft << kUpRight;
    for (char letter : kBottomRow) {
      std::cout << kColorStrings.at(color_map_.at(letter)) << letter;
    }
    std::cout << kColorStrings.at(kWhite) << kUpLeft << kDownRight;
  } else if (line == 4) {
    std::cout << ' ' << kDownLeft << std::string(7, kHori) << kDownRight;
  }
}

}  // namespace rose
