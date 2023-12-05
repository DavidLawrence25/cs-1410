#include <random>
#include <string>

#ifndef CS1410_FINALPROJECT_DICTIONARYREADER_H_
#define CS1410_FINALPROJECT_DICTIONARYREADER_H_

namespace rose {

// The file path of the legal words dictionary.
extern const std::string kLegalWordsPath;

// Represents a word list located at `file_path` with `length` words in it.
struct Dictionary {
  std::string file_path;
  size_t length;
};

// An abstract object for reading information from Dictionary structures.
class DictionaryReader {
 public:
  // Returns true if `word` is legal, regardless of its length.
  bool IsLegal(std::string word);
  // Returns a random word from the solution dictionary `dict`.
  std::string GetRandomSolution(Dictionary &dict, std::mt19937 &rng);
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_DICTIONARYREADER_H_
