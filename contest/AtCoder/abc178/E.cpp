#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> x(n), y(n);
  read(x, y);
  Vector<int> p, q;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(x[i] + y[i]);
    q.emplace_back(x[i] - y[i]);
  }
  cout << max(p.max() - p.min(), q.max() - q.min()) << endl;
}
