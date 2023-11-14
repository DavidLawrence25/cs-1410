#include <ostream>
#include <sstream>
#include <string>

#include "address.h"
#include "date.h"

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_EMPLOYEE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_EMPLOYEE_H_

namespace rose {

// Represents an employee with a name, home address, and start date.
class Employee {
 public:
  Employee() {
    name_ = "John Doe";
    start_date_ = {/*year=*/1970, /*month=*/1, /*day=*/1};
  }

  Employee(std::string name, int year, int month, int day) {
    name_ = name;
    start_date_ = {year, month, day};
  }

  ~Employee() {
    if (address_ != nullptr) {
      delete address_;
    }
  }

  void set_address(std::string street, std::string city) {
    address_ = new Address(street, city);
  }

  virtual std::string ToString();

  friend std::ostream &operator<<(std::ostream &out, Employee &employee);

 protected:
  std::string name_;
  Address *address_;
  Date start_date_;
};

std::string Employee::ToString() {
  std::stringstream result;
  result << name_ << '\n';
  if (address_ != nullptr) result << *address_;
  result << start_date_ << '\n';
  return result.str();
}

std::ostream &operator<<(std::ostream &out, Employee &employee) {
  out << employee.ToString();
  return out;
}

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_EMPLOYEE_H_
