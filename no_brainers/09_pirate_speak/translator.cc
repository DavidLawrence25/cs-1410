#include "translator.h"

#include <fstream>

namespace rose {

std::string Translator::TranslateWordToPirate(std::string word) {
  std::ifstream dictionary_file(dictionary_path_);
  std::string current_english = "";
  std::string current_pirate = "";

  while (dictionary_file.good()) {
    std::getline(dictionary_file, current_english, ',');
    std::getline(dictionary_file, current_pirate, '\n');
    if (current_english == word) break;
  }

  return current_pirate == "" ? word : current_pirate;
}

}  // namespace rose
