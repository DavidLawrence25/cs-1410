#include "puzzle.h"

#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "custom_libraries/cyclic_int.h"

// Constructs a puzzle with the tiles in the following arrangement (s = `size`):
// [       1][       2]...[      s]
// [     s+1][     s+2]...[     2s]
// ...
// [s(s-1)+1]...[   s*s-1][      0]
rose::Puzzle::Puzzle(int size) {
  size_ = abs(size);
  for (int i = 0; i < size; ++i) {
    tiles_.push_back({});
    for (int j = 0; j < size; ++j) {
      tiles_[i].push_back(i * size + j + 1);
    }
  }
  tiles_[size - 1][size - 1] = 0;
}

rose::Puzzle::Puzzle(rose::Puzzle &other) {
  size_ = other.size_;
  tiles_ = other.tiles_;
}

// Returns the position of a tile that has a given `value`.
// If no such tile exists in the puzzle, returns {-1, -1}.
std::vector<int> rose::Puzzle::get_position_of(int value) {
  if (!TileExists(value)) return {-1, -1};
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      if (tiles_[i][j] == value) return {i, j};
    }
  }
  return {-1, -1};  // Should never be reached.
}

// Returns true if `value` is present in the puzzle.
// Simply checks if `value` is in [0, size_*size_).
bool rose::Puzzle::TileExists(int value) {
  return value >= 0 && value < (size_ * size_);
}

// Returns true if `position` is inside the puzzle.
bool rose::Puzzle::TileExists(std::vector<int> position) {
  return position[0] >= 0 && position[0] < size_
      && position[1] >= 0 && position[1] < size_;
}

// Returns true if `position` corresponds to an existing tile
// that is adjacent to an empty tile.
bool rose::Puzzle::CanMoveTile(std::vector<int> position,
                               rose::Puzzle puzzle) {
  if (position.size() < 2) return false;
  int x = position[0];
  int y = position[1];
  if (!puzzle.TileExists({x, y})) return false;

  std::vector<int> up = {x, y - 1};
  std::vector<int> down = {x, y + 1};
  std::vector<int> left = {x - 1, y};
  std::vector<int> right = {x + 1, y};

  return (puzzle.TileExists(up) && puzzle.tiles_[up[0]][up[1]] == 0)
      || (puzzle.TileExists(down) && puzzle.tiles_[down[0]][down[1]] == 0)
      || (puzzle.TileExists(left) && puzzle.tiles_[left[0]][left[1]] == 0)
      || (puzzle.TileExists(right) && puzzle.tiles_[right[0]][right[1]] == 0);
}

// Returns true if the tile with the given `value` exists
// and is adjacent to an empty tile.
bool rose::Puzzle::CanMoveTile(int value, rose::Puzzle puzzle) {
  if (!puzzle.TileExists(value)) return false;
  std::vector<int> position = puzzle.get_position_of(value);
  return rose::Puzzle::CanMoveTile(position, puzzle);
}

// Returns true if the puzzle is in a solved permutation.
// Returns false immediately after finding an incorrect tile.
bool rose::Puzzle::IsSolved() {
  rose::CyclicInt expected = {0, size_ * size_ - 1};
  ++expected;
  for (std::vector<int> row : tiles_) {
    for (int x : row) {
      if (x != expected.get_value()) return false;
      ++expected;
    }
  }
  return true;
}

// Swaps the values of two tiles, specified by `position0` and `position1`.
void rose::Puzzle::SwapTiles(std::vector<int> position0,
                             std::vector<int> position1) {
  int temp = tiles_[position0[0]][position0[1]];
  tiles_[position0[0]][position0[1]] = tiles_[position1[0]][position1[1]];
  tiles_[position1[0]][position1[1]] = temp;
}

// Performs `moves` random swaps on the puzzle using the provided `rng`.
// Could theoretically last forever due to randomness,
// but will terminate in a reasonable amount of time in practice.
void rose::Puzzle::Shuffle(std::mt19937 &rng, int moves) {
  int swaps_made = 0;
  std::vector<int> empty_tile = get_position_of(0);
  std::uniform_int_distribution<int> distribution(0, 3);
  int previous_direction = -1;
  while (swaps_made < moves) {
    std::vector<int> adjacent_tile;
    int direction = distribution(rng);
    if (direction == previous_direction) continue;
    if (direction == 0) {
      adjacent_tile = {empty_tile[0], empty_tile[1] - 1};
    } else if (direction == 1) {
      adjacent_tile = {empty_tile[0], empty_tile[1] + 1};
    } else if (direction == 2) {
      adjacent_tile = {empty_tile[0] - 1, empty_tile[1]};
    } else if (direction == 3) {
      adjacent_tile = {empty_tile[0] + 1, empty_tile[1]};
    }
    if (!TileExists(adjacent_tile)) continue;
    SwapTiles(empty_tile, adjacent_tile);
    empty_tile = adjacent_tile;
    previous_direction = direction;
    ++swaps_made;
  }
}

// Returns the puzzle as a string in this format (using size_ = 4):
// [ 1][ 2][ 3][ 4]
// [ 5][ 6][ 7][ 8]
// [ 9][10][11][12]
// [13][14][15][  ]
std::string rose::Puzzle::ToString() {
  int number_width = static_cast<int>(2 * log10(size_)) + 1;
  const std::string empty_space(number_width, ' ');
  std::stringstream result;
  for (std::vector<int> row : tiles_) {
    for (int x : row) {
      if (x == 0) {
        result << '[' << empty_space << ']';
      } else {
        result << '[' << std::setw(number_width) << x << ']';
      }
    }
    result << '\n';
  }
  return result.str();
}
