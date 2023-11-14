#include "salaried_employee.h"

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALESEMPLOYEE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALESEMPLOYEE_H_

namespace rose {

// Represents an employee with sales and commission on top of set annual salary.
class SalesEmployee : public SalariedEmployee {
 public:
  SalesEmployee() {
    SalariedEmployee();
    commission_ = 0.0;
    sales_ = 0.0;
  }

  SalesEmployee(std::string name, int year, int month, int day, double salary,
                double commission, double sales) {
    SalariedEmployee(name, year, month, day, salary);
    commission_ = commission;
    sales_ = sales;
  }

  std::string ToString() override;

 private:
  double commission_;
  double sales_;
};

std::string SalesEmployee::ToString() {
  std::stringstream result;
  result << SalariedEmployee::ToString();
  result << "Commission: $" << commission_ << '\n';
  result << "Sales: $" << sales_ << '\n';
  return result.str();
}

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALESEMPLOYEE_H_
