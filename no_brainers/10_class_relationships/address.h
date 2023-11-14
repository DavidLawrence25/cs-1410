#include <ostream>
#include <string>

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_ADDRESS_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_ADDRESS_H_

namespace rose {

// Represents a basic building address with street and city names.
class Address {
 public:
  Address(std::string street, std::string city) {
    street_ = street;
    city_ = city;
  }

  friend std::ostream &operator<<(std::ostream &out, Address &address);

 private:
  std::string street_;
  std::string city_;
};

std::ostream &operator<<(std::ostream &out, Address &address) {
  out << address.street_ << ", " << address.city_ << '\n';
  return out;
}

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_ADDRESS_H_
