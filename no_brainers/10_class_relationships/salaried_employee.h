#include "employee.h"

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALARIEDEMPLOYEE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALARIEDEMPLOYEE_H_

namespace rose {

class SalariedEmployee : public Employee {
 public:
  SalariedEmployee(std::string name, int year, int month, int day,
                   double salary);

  friend std::ostream &operator<<(std::ostream &out,
                                  SalariedEmployee &employee);

 protected:
  double salary_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_SALARIEDEMPLOYEE_H_
