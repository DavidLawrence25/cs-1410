/*
	For all the code Rose wrote for CS 1410, visit this Git repository:
	https://github.com/DavidLawrence25/cs-1410
*/

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

// this would be much better suited for a class instead of a struct...
struct Movie {
	std::string title;
	int release_year;
	Rating rating;
};

void display(Movie movie) {
	std::cout << '"' << movie.title << "\" (" << RATING_NAMES.at(movie.rating) << " | " << movie.release_year << ")\n";
}

int main() {
	std::cout << "Favorite Movies!\n";
	Movie favorite_movie {"The Princess Bride", 1987, PG};
	display(favorite_movie);

	return 0;
}
