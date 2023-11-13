#include "salaried_employee.h"

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALESEMPLOYEE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALESEMPLOYEE_H_

namespace rose {

class SalesEmployee : public SalariedEmployee {
 public:
  SalesEmployee(std::string name, int year, int month, int day, double salary,
                double commission, double sales);

  friend std::ostream &operator<<(std::ostream &out, SalesEmployee &employee);

 private:
  double commission_;
  double sales_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALESEMPLOYEE_H_
