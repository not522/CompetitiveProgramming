#include "vector.hpp"

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    int n(in);
    Vector<int> a(n, in);
    a.sort();
    if (n % 2) {
      cout << "Second" << endl;
    } else {
      for (int i = 0; i < n; i += 2) {
        if (a[i] != a[i + 1]) {
          cout << "First" << endl;
          goto next;
        }
      }
      cout << "Second" << endl;
    }
  next:;
  }
}
