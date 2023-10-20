#include <iostream>

#include "labs/05_binary_number/binary_number.h"

template <typename T>
void TestResult(std::string code, T result, T expected);

int main() {
  std::cout << "== BINARY NUMBER TESTING ==\n";

  std::cout << "-- DEFAULT CONSTRUCTOR --\n";
  rose::Binary b0;
  TestResult("Binary b0;", b0.get_value(), 0);

  std::cout << "-- INTEGER CONSTRUCTOR --\n";
  rose::Binary b1 = {69};
  TestResult("Binary b1 = {69};", b1.get_value(), 69);

  std::cout << "-- STRING CONSTRUCTOR --\n";
  rose::Binary b2 = {"11000101"};
  TestResult("Binary b2 = {\"11000101\"};", b2.get_value(), 197);

  std::cout << "-- COPY CONSTRUCTOR --\n";
  rose::Binary b3 = b1;
  TestResult("Binary b3 = b1;", b3.get_value(), 69);

  std::cout << "-- BINARY -> STRING --\n";
  std::string b2_str = b2.ToString();
  std::string b2_str_expected = "11000101";
  TestResult("string b2_str = b2.ToString();", b2_str, b2_str_expected);

  std::cout << "-- BINARY + BINARY --\n";
  rose::Binary b4 = b1 + b2;
  TestResult("Binary b4 = b1 + b2;", b4.get_value(), 266);

  std::cout << "-- BINARY + INTEGER --\n";
  rose::Binary b5 = b2 + 223;
  TestResult("Binary b5 = b2 + 243;", b5.get_value(), 420);

  std::cout << "-- INTEGER + BINARY --\n";
  int x0 = 21 + b1;
  TestResult("int x0 = 21 + b1;", x0, 90);

  std::cout << "-- BINARY += BINARY --\n";
  b5 += b2;
  TestResult("b5 += b2;", b5.get_value(), 617);

  std::cout << "-- BINARY += INTEGER --\n";
  b3 += 1;
  TestResult("b3 += 1;", b3.get_value(), 70);

  std::cout << "-- INTEGER += BINARY --\n";
  int x1 = 5;
  x1 += b5;
  TestResult("int x1 = 5; x1 += b5;", x1, 622);

  std::cout << "-- BINARY - BINARY --\n";
  rose::Binary b6 = b5 - b4;
  TestResult("Binary b6 = b5 - b4;", b6.get_value(), 351);

  std::cout << "-- BINARY - INTEGER --\n";
  rose::Binary b7 = b3 - 20;
  TestResult("Binary b7 = b3 - 20;", b7.get_value(), 50);

  std::cout << "-- INTEGER - BINARY --\n";
  int x2 = 50 - b1;
  TestResult("int x2 = 50 - b1;", x2, -19);

  std::cout << "-- BINARY -= BINARY --\n";
  b6 -= b7;
  TestResult("b6 -= b7;", b6.get_value(), 301);

  std::cout << "-- BINARY -= INTEGER --\n";
  b1 -= 100;
  TestResult("b1 -= 100;", b1.get_value(), -31);

  std::cout << "-- INTEGER -= BINARY --\n";
  int x3 = 50;
  x3 -= b7;
  TestResult("int x3 = 50; x3 -= b7;", x3, 0);

  return 0;
}

template <typename T>
void TestResult(std::string code, T result, T expected) {
  std::cout << '\t' << code << '\n';
  if (result == expected) {
    std::cout << "\t[✓] " << result << " == " << expected << '\n';
  } else {
    std::cout << "\t[✗] " << result << " != " << expected << '\n';
  }
}
