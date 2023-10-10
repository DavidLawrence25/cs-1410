#include "no_brainers/06_tic_tac_toe/board.h"

rose::Board::Board() {
  for (int i = 0; i < 9; ++i) {
    tiles_[i] = kEmpty;
  }
}

rose::Board::Board(rose::Tile tiles[9]) {
  for (int i = 0; i < 9; ++i) {
    tiles_[i] = tiles[i];
  }
}

rose::Board::Board(rose::Board &other) {
  for (int i = 0; i < 9; ++i) {
    tiles_[i] = other.tiles_[i];
  }
}

rose::Tile *rose::Board::get_row(int index) {
  rose::Tile row[3];
  if (index < 0 || index > 2) {
    row[0] = row[1] = row[2] = kEmpty;
  } else {
    row[0] = tiles_[3 * index];
    row[1] = tiles_[3 * index + 1];
    row[2] = tiles_[3 * index + 2];
  }
  return row;
}

rose::Tile *rose::Board::get_column(int index) {
  rose::Tile column[3];
  if (index < 0 || index > 2) {
    column[0] = column[1] = column[2] = kEmpty;
  } else {
    column[0] = tiles_[index];
    column[1] = tiles_[index + 3];
    column[2] = tiles_[index + 6];
  }
  return column;
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
  rose::Tile *row0 = get_row(0);
  rose::Tile *row1 = get_row(1);
  rose::Tile *row2 = get_row(2);
  rose::Tile *column0 = get_column(0);
  rose::Tile *column1 = get_column(1);
  rose::Tile *column2 = get_column(2);
  rose::Tile diagonal0[3] = {tiles_[0], tiles_[4], tiles_[8]};
  rose::Tile diagonal1[3] = {tiles_[2], tiles_[4], tiles_[6]};

  // TODO: Check for horizontal lines.
  // TODO: Check for vertical lines.
  // TODO: Check for diagonal lines.
}
