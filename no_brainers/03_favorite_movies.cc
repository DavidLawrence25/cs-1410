#include <iostream>
#include <string>
#include <unordered_map>

enum Rating {
  kGeneralAudiences,
  kParentalGuidanceSuggested,
  kParentsStronglyCautioned,
  kRestricted,
  kAdultsOnly
};

// Technically could go inside the Movie struct, but this rating system isn't
// unique to movies. The enum Rating is also in the global scope.
const std::unordered_map<Rating, std::string> kRatingNames = {
  {kGeneralAudiences, "G"},
  {kParentalGuidanceSuggested, "PG"},
  {kParentsStronglyCautioned, "PG-13"},
  {kRestricted, "R"},
  {kAdultsOnly, "NC-17"}
};

struct Movie {
 public:
  std::string title;
  int release_year;
  Rating rating;

  void display() {
    std::cout << '"' << title << "\" (" << kRatingNames.at(rating)
    << " | " << release_year << ")\n";
  }
};

int main() {
  std::cout << "Favorite Movies!\n";
  Movie favorite_movie = {"The Princess Bride", 1987, kGeneralAudiences};
  favorite_movie.display();

  return 0;
}
