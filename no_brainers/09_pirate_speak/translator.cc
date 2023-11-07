#include "translator.h"

#include <fstream>
#include <sstream>

namespace rose {

Translator::Translator(std::string dictionary_path) {
  dictionary_path_ = dictionary_path;
}

// Returns the "pirate speak"-equivalent of the given English `word`.
// Returns `word` if there is no corresponding entry in the dictionary.
std::string Translator::TranslateWordToPirate(std::string word) {
  std::ifstream dictionary_file(dictionary_path_);
  std::string current_english = "";
  std::string current_pirate = "";
  bool found_entry = false;

  while (dictionary_file.good()) {
    std::getline(dictionary_file, current_english, ',');
    std::getline(dictionary_file, current_pirate, '\n');
    if (current_english != word) continue;
    found_entry = true;
    break;
  }

  return found_entry ? current_pirate : word;
}

// Returns the "pirate speak"-equivalent of the given English `sentence`.
// The space character ' ' is the only valid delimiter.
std::string Translator::TranslateSentenceToPirate(std::string sentence) {
  std::stringstream sentence_reader(sentence);
  std::stringstream translated_sentence;

  while (sentence_reader.good()) {
    std::string this_word;
    std::getline(sentence_reader, this_word, ' ');
    translated_sentence << TranslateWordToPirate(this_word) << ' ';
  }

  return translated_sentence.str();
}

// Appends a mapping from `english` to `pirate` to the dictionary.
void Translator::AddTranslation(std::string english, std::string pirate) {
  std::ofstream dictionary_file(dictionary_path_, std::ios::app);
  dictionary_file << '\n' << english << "," << pirate;
}

}  // namespace rose
