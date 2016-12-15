#include "vector.hpp"

int main() {
  int n, k, res = 0;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + k < n; ++j) {
      if (a[j] > a[j + k]) {
        swap(a[j], a[j + k]);
        ++res;
      }
    }
  }
  cout << (is_sorted(a) ? res : -1) << endl;
}
