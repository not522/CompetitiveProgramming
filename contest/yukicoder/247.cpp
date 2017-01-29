#include "vector.hpp"
#include "dp/unbounded_knapsack.hpp"

int main() {
  int c, n;
  cin >> c >> n;
  vector<int> w(n), v(n, -1);
  cin >> w;
  auto res = unboundedKnapsack<int, int, true>(c, w, v);
  cout << (res != numeric_limits<int>::min() ? -res : -1) << endl;
}
