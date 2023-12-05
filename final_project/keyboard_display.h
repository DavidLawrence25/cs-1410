#include <map>
#include <vector>

#include "drawing.h"

#ifndef CS1410_FINALPROJECT_KEYBOARDDISPLAY_H_
#define CS1410_FINALPROJECT_KEYBOARDDISPLAY_H_

namespace rose {

const size_t kKeyboardHeight = 5;
const std::string kTopRow = "QWERTYUIOP";
const std::string kHomeRow = "ASDFGHJKL";
const std::string kBottomRow = "ZXCVBNM";

class KeyboardDisplay {
 public:
  KeyboardDisplay();

  void UpdateMap(std::string word, std::vector<Color> word_colors);
  void Display(size_t line);

 private:
  std::map<char, Color> color_map_;
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_KEYBOARDDISPLAY_H_
