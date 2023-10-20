#include "time.h"

int main() {
  rose::Time time0;
  rose::Time time1 = {/*seconds=*/543};
  rose::Time time2 = {/*hours=*/1, /*minutes=*/23, /*seconds=*/45};
  rose::Time time3 = time1 + time2;

  std::cout << "time0 = " << time0 << '\n';
  time0 += 5;
  std::cout << "time0 + 5 = " << time0 << '\n';
  std::cout << "time1 = " << time1 << '\n';
  std::cout << "time2 = " << time2 << '\n';
  std::cout << "time1 + time2 = " << time3 << '\n';

  return 0;
}
