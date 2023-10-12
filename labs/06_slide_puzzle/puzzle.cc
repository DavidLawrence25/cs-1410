#include "labs/06_slide_puzzle/puzzle.h"

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

bool rose::Puzzle::CanMoveTile(std::vector<int> position) {
  if (position.size() < 2) return false;
  int x = position[0];
  int y = position[1];
  if (x >= size_ || y >= size_) return false; // also check for negatives
}
