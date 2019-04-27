#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;
  sort(a);
  auto b = partial_sum(a);
  for (int i = n - 2; i >= 0; --i) {
    if (2 * b[i] < a[i + 1]) {
      cout << (n - i - 1) << endl;
      return 0;
    }
  }
  cout << n << endl;
}
