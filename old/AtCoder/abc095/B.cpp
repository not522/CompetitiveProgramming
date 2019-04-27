#include "vector.hpp"

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  cin >> m;
  cout << n + (x - accumulate(m)) / min(m) << endl;
}
