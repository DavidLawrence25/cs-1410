#include "no_brainers/06_tic_tac_toe/board.h"

rose::Board::Board() {
  for (int i = 0; i < 9; ++i) {
    tiles_[i] = kEmpty;
  }
}

rose::Board::Board(std::vector<rose::Tile> tiles) {
  for (int i = 0; i < 9; ++i) {
    tiles_[i] = tiles[i];
  }
}

rose::Board::Board(rose::Board &other) {
  for (int i = 0; i < 9; ++i) {
    tiles_[i] = other.tiles_[i];
  }
}

rose::Tile rose::Board::get_tile(int index) {
  return index < 0 || index > 8 ? kEmpty : tiles_[index];
}

rose::Tile rose::Board::get_tile(int row, int column) {
  int index = 3 * row + column;
  return index < 0 || index > 8 ? kEmpty : tiles_[index];
}

void rose::Board::set_tile(int index, rose::Tile tile) {
  if (index < 0 || index > 8) return;
  tiles_[index] = tile;
}

void rose::Board::set_tile(int row, int column, rose::Tile tile) {
  int index = 3 * row + column;
  if (index < 0 || index > 8) return;
  tiles_[index] = tile;
}

bool rose::Board::LineExists(rose::Tile line_type) {
  // Check for horizontal lines.
  if (tiles_[0] == tiles_[1] == tiles_[2] == line_type) return true;
  if (tiles_[3] == tiles_[4] == tiles_[5] == line_type) return true;
  if (tiles_[6] == tiles_[7] == tiles_[8] == line_type) return true;
  // Check for vertical lines.
  if (tiles_[0] == tiles_[3] == tiles_[6] == line_type) return true;
  if (tiles_[1] == tiles_[4] == tiles_[7] == line_type) return true;
  if (tiles_[2] == tiles_[5] == tiles_[8] == line_type) return true;
  // Check for diagonal lines.
  if (tiles_[0] == tiles_[4] == tiles_[8] == line_type) return true;
  if (tiles_[2] == tiles_[4] == tiles_[6] == line_type) return true;

  return false;
}
