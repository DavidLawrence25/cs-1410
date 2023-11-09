#include <math.h>

#include <string>
#include <unordered_set>

#ifndef CS1410_CUSTOMLIBRARIES_NUMBERUTILS_H_
#define CS1410_CUSTOMLIBRARIES_NUMBERUTILS_H_

namespace rose {

// Calculates the square root of `x`, rounded down to the nearest integer.
int FloorSqrt(int x);

// Returns an unordered set containing the factors of `x`.
std::unordered_set<int> FactorsOf(int x);

// Returns true when `x` is a prime number.
bool IsPrime(int x);

// Returns the value of a string `str`, interpreted as an integer in base 10.
int StringToInt(std::string str);

// Returns the value of a string `str`, interpreted as an double in base 10.
double StringToDouble(std::string str);

}  // namespace rose

#endif  // CS1410_CUSTOMLIBRARIES_NUMBERUTILS_H_