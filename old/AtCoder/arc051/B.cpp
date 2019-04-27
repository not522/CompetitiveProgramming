#include "template.hpp"

int main() {
  int k;
  cin >> k;
  vector<int> fib(42, 1);
  adjacent_difference(fib.begin(), fib.end() - 1, fib.begin() + 1, std::plus<int>());
  cout << fib[k + 1] << " " << fib[k] << endl;
}
