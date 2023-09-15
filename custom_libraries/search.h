#include <vector>

#ifndef CS1410_CUSTOMLIBRARIES_SEARCH_H_
#define CS1410_CUSTOMLIBRARIES_SEARCH_H_

// Returns the index of `value` in a sorted vector `numbers`, if present.
// If the value is not present, returns -1.
int BinarySearch(std::vector<int> numbers, int value) {
  int left_bound = 0, right_bound = numbers.size() - 1;

  while (left_bound <= right_bound) {
    // This roundabout way of calculating the arithmetic mean
    // helps prevent an integer overflow.
    int middle_index = left_bound + (right_bound - left_bound) >> 1;
    if (numbers.at(middle_index) < value) {
      left_bound = middle_index + 1;
    } else if (numbers.at(middle_index) > value) {
      right_bound = middle_index - 1;
    } else {
      return middle_index;
    }
  }

  return -1;
}

#endif // CS1410_CUSTOMLIBRARIES_SEARCH_H_
