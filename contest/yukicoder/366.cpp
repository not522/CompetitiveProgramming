#include "vector.hpp"

int main() {
  int n(in), k(in), res = 0;
  Vector<int> a(n, in);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + k < n; ++j) {
      if (a[j] > a[j + k]) {
        swap(a[j], a[j + k]);
        ++res;
      }
    }
  }
  cout << (a.is_sorted() ? res : -1) << endl;
}
