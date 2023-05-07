#include "stack.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in), b(n, in);
  Stack<int> c;
  Vector<bool> ok(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      ok[i] = true;
      while (!c.empty() && a[c.peek()] >= a[i] - b[i]) {
        ok[c.top()] = true;
      }
    } else {
      c.emplace(i);
    }
  }
  int res = c.size(), k = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] > b[i]) {
      continue;
    }
    chmin(res, max(b[i] - a[i] + 1, k));
    if (!ok[i]) {
      ++k;
    }
  }
  cout << res << endl;
}
