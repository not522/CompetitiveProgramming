#include "map.hpp"
#include "vector.hpp"

int main() {
  int64_t n(in), l(in);
  Vector<int64_t> a(n, in), b(n, in);
  Map<int64_t, int64_t> aa, bb;
  Vector<bool> ok(n);
  for (int64_t i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      ok[i] = true;
    }
  }
  aa[n] = -1;
  int64_t res = 0;
  for (int64_t i = 0; i < n; ++i) {
    if (aa.contains(b[i] + (n - i - 1))) {
      ok[i] = true;
      if (a[i] != b[i]) {
        res += i - aa[b[i] + (n - i - 1)];
      }
      aa[b[i] + (n - i - 1)] = i;
    }
    aa[a[i] + (n - i - 1)] = i;
  }
  bb[l - n + 1] = n;
  for (int64_t i = n - 1; i >= 0; --i) {
    if (bb.contains(b[i] - i)) {
      ok[i] = true;
      if (a[i] != b[i]) {
        res += bb[b[i] - i] - i;
      }
      bb[b[i] - i] = i;
    }
    bb[a[i] - i] = i;
  }
  if (!ok.all_of([](bool f) { return f; })) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}
