#include "vector.hpp"

int main() {
  int n(in), k(in);
  if (n <= k) {
    cout << 0 << endl;
    return 0;
  }
  Vector<int64_t> h(n, in);
  cout << h.nth_element(n - k).subvector(0, n - k).accumulate() << endl;
}
