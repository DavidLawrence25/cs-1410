#include "employee.h"

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALARIEDEMPLOYEE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALARIEDEMPLOYEE_H_

namespace rose {

// Represents an employee with a predetermined annual salary.
class SalariedEmployee : public Employee {
 public:
  SalariedEmployee() {
    Employee();
    salary_ = 0.0;
  }

  SalariedEmployee(std::string name, int year, int month, int day,
                   double salary) : Employee(name, year, month, day) {
    salary_ = salary;
  }

  virtual std::string ToString() override;

 protected:
  double salary_;
};

std::string SalariedEmployee::ToString() {
  std::stringstream result;
  result << Employee::ToString();
  result << "Salary: $" << salary_ << '\n';
  return result.str();
}

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALARIEDEMPLOYEE_H_
