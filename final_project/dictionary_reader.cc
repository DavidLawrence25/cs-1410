#include "dictionary_reader.h"

#include <fstream>

namespace rose {

const std::string kLegalWordsPath = "final_project/legal_words.txt";

bool DictionaryReader::IsLegal(std::string word) {
  std::ifstream legal_file(kLegalWordsPath);
  std::string this_word;
  bool found_word = false;

  while (legal_file.good() && !found_word) {
    std::getline(legal_file, this_word);
    found_word = (this_word == word);
  }

  return found_word;
}

std::string DictionaryReader::GetRandomSolution(Dictionary &dict,
                                                std::mt19937 &rng) {
  std::uniform_int_distribution<int> word_distribution(0, dict.length - 1);
  size_t target_index = word_distribution(rng);
  std::string this_word;
  std::ifstream dict_file(dict.file_path);

  for (size_t i = 0; i <= target_index; ++i) {
    std::getline(dict_file, this_word);
  }

  dict_file.close();
  return this_word;
}

}  // namespace rose
