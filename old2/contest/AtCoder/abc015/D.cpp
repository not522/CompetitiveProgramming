#include "vector.hpp"

int main() {
  int w(in), n(in), k(in);
  Vector<int> a(n), b(n);
  read(a, b);
  auto dp = Vector<int>::makeVector(k + 1, w + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = k; j > 0; --j) {
      for (int l = 0; l + a[i] <= w; ++l) {
        chmax(dp[j][l + a[i]], dp[j - 1][l] + b[i]);
      }
    }
  }
  cout << dp.max([](const Vector<int> &v) { return v.back(); }).back() << endl;
}
