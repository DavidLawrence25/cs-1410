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

std::vector<rose::Tile> rose::Board::get_row(int index) {
  if (index < 0 || index > 2) return {kEmpty, kEmpty, kEmpty};
  return {tiles_[3 * index], tiles_[3 * index + 1], tiles_[3 * index + 2]};
}

std::vector<rose::Tile> rose::Board::get_column(int index) {
  if (index < 0 || index > 2) return {kEmpty, kEmpty, kEmpty};
  return {tiles_[index], tiles_[index + 3], tiles_[index + 6]};
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
  std::vector<rose::Tile> row0 = get_row(0);
  std::vector<rose::Tile> row1 = get_row(1);
  std::vector<rose::Tile> row2 = get_row(2);
  std::vector<rose::Tile> column0 = get_column(0);
  std::vector<rose::Tile> column1 = get_column(1);
  std::vector<rose::Tile> column2 = get_column(2);
  std::vector<rose::Tile> diagonal0 = {tiles_[0], tiles_[4], tiles_[8]};
  std::vector<rose::Tile> diagonal1 = {tiles_[2], tiles_[4], tiles_[6]};

  // TODO: Check for horizontal lines.
  // TODO: Check for vertical lines.
  // TODO: Check for diagonal lines.
}
