#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<char> c(n, in);
  c.rsort();
  int p = c.count('+') + 1, m = c.count('-');
  c.resize(n - p - m + 1);
  n = c.size();
  int64_t mx = 0, mn = 0;
  for (int i = 0; i < n - p - m; ++i) {
    mx = (mx + c[i] - '0') * 10;
  }
  for (int i = n - p - m; i < n - m; ++i) {
    mx += c[i] - '0';
  }
  for (int i = n - m; i < n; ++i) {
    mx -= c[i] - '0';
  }
  if (m == 0) {
    for (int i = 0; i < n; ++i) {
      mn += (c[i] - '0') * pow(10, i / p);
    }
  } else {
    for (int i = 0; i < n - p - m; ++i) {
      mn = (mn - c[i] + '0') * 10;
    }
    for (int i = n - p - m; i < n - p; ++i) {
      mn -= c[i] - '0';
    }
    for (int i = n - p; i < n; ++i) {
      mn += c[i] - '0';
    }
  }
  cout << mx << " " << mn << endl;
}
