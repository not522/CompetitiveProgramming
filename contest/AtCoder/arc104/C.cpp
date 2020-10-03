#include "set.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n), b(n);
  read(a, b);
  --a;
  --b;
  Vector<bool> ok(2 * n + 1);
  ok[2 * n] = true;
  for (int i = 2 * n - 2; i >= 0; i -= 2) {
    for (int j = i + 2; j <= 2 * n; j += 2) {
      if (!ok[j]) {
        continue;
      }
      int m = (i + j) / 2;
      ok[i] = true;
      Set<int> s;
      for (int k = 0; k < n; ++k) {
        if (m <= a[k] && a[k] < j) {
          ok[i] = false;
          break;
        }
        if (i <= b[k] && b[k] < m) {
          ok[i] = false;
          break;
        }
        if (i <= a[k] && a[k] < m) {
          if (s.contains(a[k])) {
            ok[i] = false;
            break;
          }
          s.emplace(a[k]);
          if (b[k] >= 0 && b[k] != a[k] + (j - i) / 2) {
            ok[i] = false;
            break;
          }
        } else if (m <= b[k] && b[k] < j) {
          if (s.contains(b[k] - (j - i) / 2)) {
            ok[i] = false;
            break;
          }
          s.emplace(b[k] - (j - i) / 2);
          if (a[k] >= 0) {
            ok[i] = false;
            break;
          }
        }
      }
      if (ok[i]) {
        break;
      }
    }
  }
  cout << ok[0] << endl;
}
