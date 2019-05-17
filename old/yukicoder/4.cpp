#include "dp/knapsack.hpp"

int main() {
  setBoolName("possible", "impossible");
  int n(in);
  Vector<int> w(n, in);
  static const int sum = w.accumulate();
  cout << (sum % 2 == 0 && knapsackFill(sum / 2, w).back()) << endl;
}
