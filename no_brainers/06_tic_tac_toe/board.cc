#include "no_brainers/06_tic_tac_toe/board.h"

#include <sstream>
#include <string>
#include <vector>

#include "no_brainers/06_tic_tac_toe/tile.h"

rose::Board::Board() {
  for (int i = 0; i < 9; ++i) tiles_.push_back(kEmpty);
}

rose::Board::Board(std::vector<rose::Tile> tiles) {
  tiles_ = tiles;
}

rose::Board::Board(rose::Board &other) {
  tiles_ = other.tiles_;
}

rose::Tile rose::Board::get_tile(int index) {
  return IsValidIndex(index) ? tiles_[index] : kEmpty;
}

rose::Tile rose::Board::get_tile(int row, int column) {
  int index = 3 * row + column;
  return IsValidIndex(index) ? tiles_[index] : kEmpty;
}

void rose::Board::set_tile(int index, rose::Tile tile) {
  if (IsValidIndex(index)) tiles_[index] = tile;
}

void rose::Board::set_tile(int row, int column, rose::Tile tile) {
  int index = 3 * row + column;
  if (IsValidIndex(index)) tiles_[index] = tile;
}

bool rose::Board::TileExists(rose::Tile tile_type) {
  for (rose::Tile tile : tiles_) {
    if (tile == tile_type) return true;
  }
  return false;
}

bool rose::Board::LineExists(rose::Tile line_type) {
  // Check for horizontal lines.
  if (tiles_[0] == line_type && tiles_[1] == line_type
      && tiles_[2] == line_type) return true;
  if (tiles_[3] == line_type && tiles_[4] == line_type
      && tiles_[5] == line_type) return true;
  if (tiles_[6] == line_type && tiles_[7] == line_type
      && tiles_[8] == line_type) return true;
  // Check for vertical lines.
  if (tiles_[0] == line_type && tiles_[3] == line_type
      && tiles_[6] == line_type) return true;
  if (tiles_[1] == line_type && tiles_[4] == line_type
      && tiles_[7] == line_type) return true;
  if (tiles_[2] == line_type && tiles_[5] == line_type
      && tiles_[8] == line_type) return true;
  // Check for diagonal lines.
  if (tiles_[0] == line_type && tiles_[4] == line_type
      && tiles_[8] == line_type) return true;
  if (tiles_[2] == line_type && tiles_[4] == line_type
      && tiles_[6] == line_type) return true;

  return false;
}

bool rose::Board::CanPlaceTile(int index, rose::Board board) {
  return IsValidIndex(index) && board.get_tile(index) == kEmpty;
}

std::string rose::Board::ToString() {
  std::stringstream result;
  result << "Current Board: \n";
  for (int i = 0; i < 9; ++i) {
    rose::Tile tile = tiles_[i];
    if (tile != kEmpty) {
      result << rose::kTileChar.at(tile);
    } else {
      result << i;
    }
    if (i % 3 != 2) {
      result << " | ";
    } else {
      result << '\n';
      if (i != 8) result << "--+---+--\n";
    }
  }
  return result.str();
}

bool rose::Board::IsValidIndex(int index) {
  return index >= 0 && index < 9;
}
