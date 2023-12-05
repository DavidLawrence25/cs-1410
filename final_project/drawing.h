#include <string>
#include <unordered_map>

#ifndef CS1410_FINALPROJECT_DRAWING_H_
#define CS1410_FINALPROJECT_DRAWING_H_

namespace rose {

enum Color { kWhite, kGray, kYellow, kGreen };

// Maps color codes to ANSI escape sequences that
// color each subsequent character accordingly.
const std::unordered_map<Color, std::string> kColorStrings = {
    {kWhite, "\033[0m"},
    {kGray, "\033[38;5;248m"},
    {kYellow, "\033[33m"},
    {kGreen, "\033[32m"}};

// Various box-drawing characters.
const char kUpLeft = '\xC9';     // ╔
const char kUpRight = '\xBB';    // ╗
const char kDownLeft = '\xC8';   // ╚
const char kDownRight = '\xBC';  // ╝
const char kHori = '\xCD';       // ═
const char kVert = '\xBA';       // ║

}  // namespace rose

#endif  // CS1410_FINALPROJECT_DRAWING_H_
