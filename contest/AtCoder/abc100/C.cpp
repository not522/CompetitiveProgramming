#include "bit_operation.hpp"
#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i : a) res += least_bit_fast(i);
  cout << res << endl;
}
