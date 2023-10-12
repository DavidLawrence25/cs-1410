#include "labs/06_slide_puzzle/puzzle.h"

#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

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

std::vector<int> rose::Puzzle::get_position_of(int value) {
  if (!TileExists(value)) return {-1, -1};
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      if (tiles_[i][j] == value) return {i, j};
    }
  }
}

bool rose::Puzzle::TileExists(int value) {
  return value >= 0 && value < (size_ * size_);
}

bool rose::Puzzle::TileExists(std::vector<int> position) {
  return position[0] >= 0 && position[0] < size_
      && position[1] >= 0 && position[1] < size_;
}

bool rose::Puzzle::CanMoveTile(std::vector<int> position) {
  if (position.size() < 2) return false;
  int x = position[0];
  int y = position[1];
  if (!TileExists({x, y})) return false;

  std::vector<int> up = {x, y - 1};
  std::vector<int> down = {x, y + 1};
  std::vector<int> left = {x - 1, y};
  std::vector<int> right = {x + 1, y};

  if (TileExists(up) && tiles_[up[0]][up[1]] == 0) return true;
  if (TileExists(down) && tiles_[down[0]][down[1]] == 0) return true;
  if (TileExists(left) && tiles_[left[0]][left[1]] == 0) return true;
  if (TileExists(right) && tiles_[right[0]][right[1]] == 0) return true;

  return false;
}

bool rose::Puzzle::CanMoveTile(int value) {
  if (!TileExists(value)) return false;
  std::vector<int> position = get_position_of(value);
  return CanMoveTile(position);
}

void rose::Puzzle::SwapTiles(std::vector<int> position0,
                             std::vector<int> position1) {
  int temp = tiles_[position0[0]][position0[1]];
  tiles_[position0[0]][position0[1]] = tiles_[position1[0]][position1[1]];
  tiles_[position1[0]][position1[1]] = temp;
}

void rose::Puzzle::Shuffle(std::mt19937 &rng, int moves) {
  int swaps_made = 0;
  std::vector<int> empty_tile = get_position_of(0);
  std::uniform_int_distribution<int> distribution(0, 3);
  while (swaps_made < moves) {
    std::vector<int> adjacent_tile;
    switch (distribution(rng)) {
      case 0:
        adjacent_tile = {empty_tile[0], empty_tile[1] - 1};
        break;
      case 1:
        adjacent_tile = {empty_tile[0], empty_tile[1] + 1};
        break;
      case 2:
        adjacent_tile = {empty_tile[0] - 1, empty_tile[1]};
        break;
      case 3:
        adjacent_tile = {empty_tile[0] + 1, empty_tile[1]};
        break;
      default: break;
    }
    if (!TileExists(adjacent_tile)) continue;
    SwapTiles(empty_tile, adjacent_tile);
    ++swaps_made;
  }
}

std::string rose::Puzzle::ToString() {
  int number_width = static_cast<int>(2 * log10(size_)) + 1;
  std::stringstream result;
  for (std::vector<int> row : tiles_) {
    for (int x : row) {
      result << '[' << std::setw(number_width) << x << ']';
    }
    result << '\n';
  }
  return result.str();
}
