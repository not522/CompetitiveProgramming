#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  cin >> x;
  for (int& i : x) i = min(i, k - i);
  cout << 2 * accumulate(x) << endl;
}
