#include <iostream>
#include <vector>

#include "address.h"
#include "custom_libraries/user_input.h"
#include "date.h"
#include "employee.h"
#include "salaried_employee.h"
#include "sales_employee.h"
#include "waged_employee.h"

typedef void (*MenuAction)(std::vector<rose::Employee *>&);

MenuAction Menu();
void AddSalariedEmployee(std::vector<rose::Employee *> &employees);
void AddSalesEmployee(std::vector<rose::Employee *> &employees);
void AddWagedEmployee(std::vector<rose::Employee *> &employees);
void ListEmployees(std::vector<rose::Employee *> &employees);
void Quit(std::vector<rose::Employee *> &employees);

const std::string kInvalidInputMessage = "Invalid input. Please try again\n";

int main() {
  std::vector<rose::Employee *> employees;
  std::cout << "== EMPLOYEE LIST CREATOR ==\n";

  while (true) {
    (*Menu())(employees);
    std::cout << '\n';
  }
}

MenuAction Menu() {
  return rose::MenuPrompt<MenuAction>(
      "1. Add Waged Employee\n2. Add Salaried Employee\n3. Add Sales Employee\n4. List Employees\n5. Quit\n> ",
      kInvalidInputMessage, {{"1", AddWagedEmployee},
      {"2", AddSalariedEmployee}, {"3", AddSalesEmployee}, {"4", ListEmployees},
      {"5", Quit}});
}

void AddSalariedEmployee(std::vector<rose::Employee *> &employees) {
  std::cin.ignore();

  std::cout << "\n-- ADD SALARIED EMPLOYEE --\n";

  std::string name;
  std::cout << "Name > ";
  std::getline(std::cin, name);

  double salary = rose::GetDouble("Salary > ", kInvalidInputMessage);

  int year = rose::GetInteger("Year > ", kInvalidInputMessage);
  int month = rose::GetInteger("Month > ", kInvalidInputMessage);
  int day = rose::GetInteger("Day > ", kInvalidInputMessage);

  std::cin.ignore();

  std::string street;
  std::string city;
  std::cout << "Street > ";
  std::getline(std::cin, street);
  std::cout << "City > ";
  std::getline(std::cin, city);

  rose::SalariedEmployee *to_add = new rose::SalariedEmployee(name, year, month,
                                                              day, salary);
  to_add->set_address(street, city);
  employees.push_back(to_add);
}

void AddSalesEmployee(std::vector<rose::Employee *> &employees) {
  std::cin.ignore();

  std::cout << "\n-- ADD SALES EMPLOYEE --\n";

  std::string name;
  std::cout << "Name > ";
  std::getline(std::cin, name);

  double salary = rose::GetDouble("Salary > ", kInvalidInputMessage);
  double commission = rose::GetDouble("Commission > ", kInvalidInputMessage);
  double sales = rose::GetDouble("Sales > ", kInvalidInputMessage);

  int year = rose::GetInteger("Year > ", kInvalidInputMessage);
  int month = rose::GetInteger("Month > ", kInvalidInputMessage);
  int day = rose::GetInteger("Day > ", kInvalidInputMessage);

  std::cin.ignore();

  std::string street;
  std::string city;
  std::cout << "Street > ";
  std::getline(std::cin, street);
  std::cout << "City > ";
  std::getline(std::cin, city);

  rose::SalesEmployee *to_add = new rose::SalesEmployee(name, year, month, day,
                                                        salary, commission,
                                                        sales);
  to_add->set_address(street, city);
  employees.push_back(to_add);
}

void AddWagedEmployee(std::vector<rose::Employee *> &employees) {
  std::cin.ignore();

  std::cout << "\n-- ADD WAGED EMPLOYEE --\n";

  std::string name;
  std::cout << "Name > ";
  std::getline(std::cin, name);

  double wage = rose::GetDouble("Wage > ", kInvalidInputMessage);
  double hours = rose::GetDouble("Hours > ", kInvalidInputMessage);

  int year = rose::GetInteger("Year > ", kInvalidInputMessage);
  int month = rose::GetInteger("Month > ", kInvalidInputMessage);
  int day = rose::GetInteger("Day > ", kInvalidInputMessage);

  std::cin.ignore();

  std::string street;
  std::string city;
  std::cout << "Street > ";
  std::getline(std::cin, street);
  std::cout << "City > ";
  std::getline(std::cin, city);

  rose::WagedEmployee *to_add = new rose::WagedEmployee(name, year, month, day,
                                                        wage, hours);
  to_add->set_address(street, city);
  employees.push_back(to_add);
}

void ListEmployees(std::vector<rose::Employee *> &employees) {
  std::cout << "\n-- EMPLOYEE LIST --\n";
  for (rose::Employee *employee : employees) std::cout << '\n' << *employee;
}

void Quit(std::vector<rose::Employee *> &employees) {
  exit(0);
}
