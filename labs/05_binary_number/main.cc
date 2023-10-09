#include <iostream>

#include "labs/05_binary_number/binary_number.cc"

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
  rose::Binary b6 = 21 + b1;
  TestResult("Binary b6 = 21 + b1;", b6.get_value(), 90);

  std::cout << "-- BINARY += BINARY --\n";
  b6 += b2;
  TestResult("b6 += b2;", b6.get_value(), 287);

  std::cout << "-- BINARY += INTEGER --\n";
  b3 += 1;
  TestResult("b3 += 1;", b3.get_value(), 70);

  std::cout << "-- INTEGER += BINARY --\n";
  int x = 5;
  x += b6;
  TestResult("int x = 5; x += b6;", x, 292);

  std::cout << "-- BINARY - BINARY --\n";
  rose::Binary b7 = b6 - b5;
  TestResult("Binary b7 = b6 - b5;", b7.get_value(), -133);

  std::cout << "-- BINARY - INTEGER --\n";
  rose::Binary b8 = b5 - 20;
  TestResult("Binary b8 = b5 - 20;", b8.get_value(), 400);

  std::cout << "-- INTEGER - BINARY --\n";
  rose::Binary b9 = 50 - b5;
  TestResult("Binary b9 = 50 - b5;", b9.get_value(), -370);

  std::cout << "-- BINARY -= BINARY --\n";
  b8 -= b9;
  TestResult("b8 -= b9;", b8.get_value(), 770);

  std::cout << "-- BINARY -= INTEGER --\n";
  b8 -= 800;
  TestResult("b8 -= 800;", b8.get_value(), -30);

  std::cout << "-- INTEGER -= BINARY --\n";
  int y = 50;
  y -= b8;
  TestResult("int y = 50; y -= b8;", y, 80);

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
