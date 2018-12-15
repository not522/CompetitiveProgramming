#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  rsort(a);
  int64_t x = 0, y = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] == a[i + 1]) {
      if (x == 0) {
        x = a[i];
      } else {
        y = a[i];
        break;
      }
      ++i;
    }
  }
  cout << x * y << endl;
}
