#include <map>
#include <vector>

#include "drawing.h"

#ifndef CS1410_FINALPROJECT_KEYBOARDDISPLAY_H_
#define CS1410_FINALPROJECT_KEYBOARDDISPLAY_H_

namespace rose {

// The number of lines occupied by the keyboard display.
extern const size_t kKeyboardHeight;
// The characters included in the top row of the QWERTY keyboard.
extern const std::string kTopRow;
// The characters included in the middle (or home) row of the QWERTY keyboard.
extern const std::string kHomeRow;
// The characters included in the bottom row of the QWERTY keyboard.
extern const std::string kBottomRow;

// Represents a keyboard in the user interface
// that summarizes the information collected so far.
class KeyboardDisplay {
 public:
  KeyboardDisplay();

  // Updates the color map to include new information gained from `word`.
  void UpdateMap(std::string word, std::vector<Color> word_colors);
  // Displays a single line of the keyboard.
  void Display(size_t line);

 private:
  // Maps letters to colors on the keyboard.
  std::map<char, Color> color_map_;
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_KEYBOARDDISPLAY_H_
