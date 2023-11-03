#include <iostream>

#include "queue.h"

void ResolveFirstIssue(rose::Queue<std::string> &queue);

int main() {
  std::cout << "== FIFO QUEUE TESTING (STRINGS) ==\n";
  rose::Queue<std::string> customers_on_hold;

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
  customers_on_hold.~Queue();

  std::cout << "== FIFO QUEUE TESTING (INTEGERS) ==\n";

  rose::Queue<int> to_sort;
  rose::Queue<int> temp0;
  rose::Queue<int> temp1;

  to_sort.Add(6);
  to_sort.Add(7);
  to_sort.Add(3);
  to_sort.Add(5);
  to_sort.Add(4);
  to_sort.Add(1);
  to_sort.Add(8);
  to_sort.Add(2);

  std::cout << "-- Queues Created --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp0.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 6 to Temp 0 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 7 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(temp0.Peek());
  temp0.Remove();

  std::cout << "-- Sent 6 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp0.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 3 to Temp 0 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 5 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 4 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(temp0.Peek());
  temp0.Remove();

  std::cout << "-- Sent 3 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp0.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 1 to Temp 0 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp0.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 8 to Temp 0 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(to_sort.Peek());
  to_sort.Remove();

  std::cout << "-- Sent 2 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  temp1.Add(temp0.Peek());
  temp0.Remove();

  std::cout << "-- Sent 1 to Temp 1 --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  to_sort.Add(temp0.Peek());
  temp0.Remove();

  std::cout << "-- Sent 8 to Numbers to Sort --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  for (size_t i = 0; i < 7; ++i) {
    to_sort.Add(temp1.Peek());
    temp1.Remove();
  }

  std::cout << "-- Transferred Temp 1 to Numbers to Sort --\n";
  std::cout << "Numbers to Sort: " << to_sort << '\n';
  std::cout << "Temp 0: " << temp0 << '\n';
  std::cout << "Temp 1: " << temp1 << '\n';

  std::cout << "-- Sorting Complete --\n";
  to_sort.~Queue();
  temp0.~Queue();
  temp1.~Queue();

  return 0;
}

void ResolveFirstIssue(rose::Queue<std::string> &queue) {
  std::cout << "-- Resolved " << queue.Peek() << "'s Issue --\n";
  queue.Remove();
}
