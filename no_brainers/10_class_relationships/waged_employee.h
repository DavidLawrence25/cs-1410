#include "employee.h"

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_WAGEDEMPLOYEE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_WAGEDEMPLOYEE_H_

namespace rose {

class WagedEmployee : public Employee {
 public:
  WagedEmployee() {
    Employee();
    wage_ = 0.0;
    hours_ = 0.0;
  }

  WagedEmployee(std::string name, int year, int month, int day, double wage,
                double hours) {
    Employee(name, year, month, day);
    wage_ = wage;
    hours_ = hours;
  }

  std::string ToString() override;

  friend std::ostream &operator<<(std::ostream &out, WagedEmployee &employee);

 private:
  double wage_;
  double hours_;
};

std::string WagedEmployee::ToString() {
  std::stringstream result;
  result << Employee::ToString();
  result << "Wage: $" << wage_ << "/hr\n";
  result << "Hours: " << hours_ << '\n';
  result << "Salary: $" << wage_ * hours_ << '\n';
  return result.str();
}

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_WAGEDEMPLOYEE_H_
