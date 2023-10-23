#include <iostream>

#include "queue.h"

void ResolveFirstIssue(rose::Queue &queue);

int main() {
  std::cout << "== FIFO QUEUE TESTING ==\n";

  rose::Queue customers_on_hold;

  customers_on_hold.Add("Alice");
  customers_on_hold.Add("Bob");
  customers_on_hold.Add("Charlie");

  std::cout << "-- Alice, Bob, & Charlie Joined the Queue --\n";
  std::cout << "Customers on Hold: " << customers_on_hold << '\n';

  ResolveFirstIssue(customers_on_hold);

  std::cout << "Customers on Hold: " << customers_on_hold << '\n';

  customers_on_hold.Add("Derek");
  customers_on_hold.Add("Ella");

  std::cout << "-- Derek & Ella Joined the Queue --\n";
  std::cout << "Customers on Hold: " << customers_on_hold << '\n';

  for (size_t i = 0; i < 4; ++i) ResolveFirstIssue(customers_on_hold);

  std::cout << "Customers on Hold: " << customers_on_hold << '\n';

  if (customers_on_hold.IsEmpty()) std::cout << "-- Queue Cleared --\n";
  return 0;
}

void ResolveFirstIssue(rose::Queue &queue) {
  std::cout << "-- Resolved " << queue.Peek() << "'s Issue --\n";
  queue.Remove();
}
