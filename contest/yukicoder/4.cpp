#include "dp/knapsack.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int& i : w) cin >> i;
  static const int sum = accumulate(w.begin(), w.end(), 0);
  cout << (sum % 2 == 0 && knapsackFill(sum / 2, w).back() ? "possible" : "impossible") << endl;
}
