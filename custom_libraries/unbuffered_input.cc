#include "unbuffered_input.h"

#include <conio.h>

namespace rose {

char MakeUppercase(char letter) {
  return (letter >= 'a' && letter <= 'z') ? letter - 32 : letter;
}

char MakeLowercase(char letter) {
  return (letter >= 'A' && letter <= 'Z') ? letter + 32 : letter;
}

bool IsAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool HasAlpha(std::string s) {
  bool seen = false;

  for (char c : s) {
    if (IsAlpha(c)) {
      seen = true;
      break;
    }
  }

  return seen;
}

bool IsNum(char c) { return (c >= '0' && c <= '9'); }

bool HasNum(std::string s) {
  bool seen = false;

  for (char c : s) {
    if (IsNum(c)) {
      seen = true;
      break;
    }
  }

  return seen;
}

bool IsSymbol(char c) {
  return (c >= ' ' && c <= '/') || (c >= ':' && c <= '@') ||
         (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

bool HasSymbol(std::string s) {
  bool seen = false;

  for (char c : s) {
    if (IsSymbol(c)) {
      seen = true;
      break;
    }
  }

  return seen;
}

}  // namespace rose
