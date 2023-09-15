#include <iostream>
#include <string>
#include <unordered_map>

enum Rating {G, PG, PG13, R, X};
std::unordered_map<Rating, std::string> RATING_NAMES {
	{G, "G"},
	{PG, "PG"},
	{PG13, "PG-13"},
	{R, "R"},
	{X, "X"}
};

struct Movie {
	std::string title;
	int release_year;
	Rating rating;

	void display();
};

void Movie::display() {
	std::cout << '"' << title << "\" (" << RATING_NAMES.at(rating) << " | " << release_year << ")\n";
}

int main() {
	std::cout << "Favorite Movies!\n";
	Movie favorite_movie {"The Princess Bride", 1987, PG};
	favorite_movie.display();

	return 0;
}
