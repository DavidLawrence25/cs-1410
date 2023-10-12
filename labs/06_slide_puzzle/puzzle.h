#include <random>
#include <vector>

#ifndef CS1410_LABS_06SLIDEPUZZLE_PUZZLE_H_
#define CS1410_LABS_06SLIDEPUZZLE_PUZZLE_H_

namespace rose {

// Represents a slide puzzle.
class Puzzle {
 public:
  Puzzle(int size);
  Puzzle(Puzzle &other);

  std::vector<int> get_position_of(int value);

  // Returns true if a tile exists in the puzzle with the given `value`.
  bool TileExists(int value);
  // Returns true if the tile at `position` is adjacent to an empty tile.
  bool CanMoveTile(std::vector<int> position);
  // Returns true if a tile with the given `value` is adjacent to an empty tile.
  bool CanMoveTile(int value);
  // Swaps the values of two tiles, specified by `position0` and `position1`.
  void SwapTiles(std::vector<int> position0, std::vector<int> position1);
  // Shuffles the puzzle with `moves` number of moves.
  void Shuffle(std::mt19937 rng, int moves);

 private:
  int size_;
  std::vector<std::vector<int>> tiles_;
};

}

#endif  // CS1410_LABS_06SLIDEPUZZLE_PUZZLE_H_