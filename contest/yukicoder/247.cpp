#include "dp/unbounded_knapsack.hpp"
#include "vector.hpp"

int main() {
  int c(in), n(in);
  Vector<int> w(n, in), v(n, -1);
  auto res = unboundedKnapsack<int, int, true>(c, w, v);
  cout << (res != -inf<int>() ? -res : -1) << endl;
}
