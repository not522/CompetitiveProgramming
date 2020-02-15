#include "queue.hpp"
#include "vector.hpp"

int main() {
  int n(in), t = 0;
  Vector<int> x(n, in), a(n * n), cnt(n);
  for (int i = 0; i < n; ++i) {
    a[x[i] - 1] = i + 1;
  }
  auto arg = x.argsort();
  Queue<int> used;
  for (int i = 0; i < n * n; ++i) {
    if (a[i] != 0) {
      if (cnt[a[i] - 1] != a[i] - 1) {
        cout << false << endl;
        return 0;
      }
      continue;
    }
    while (t < n && cnt[arg[t]] == arg[t]) {
      used.emplace(arg[t]);
      ++t;
    }
    if (t < n) {
      a[i] = arg[t] + 1;
      ++cnt[arg[t]];
    } else {
      bool ok = true;
      while (!used.empty()) {
        int j = used.peek();
        a[i] = j + 1;
        if (cnt[j] == n - 1) {
          used.pop();
          continue;
        }
        ++cnt[j];
        ok = true;
        break;
      }
      if (!ok) {
        cout << false << endl;
        return 0;
      }
    }
  }
  cout << true << endl;
  a.output(" ");
}
