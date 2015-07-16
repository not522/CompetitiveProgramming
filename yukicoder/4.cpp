#include "dp/knapsack.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int& i : w) cin >> i;
  static const int sum = accumulate(w.begin(), w.end(), 0);
  cout << (sum % 2 == 0 && knapsack(sum / 2, w, vector<int>(n, 1), 1, multiplies<int>()) ? "possible" : "impossible") << endl;
}
