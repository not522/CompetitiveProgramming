#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int x(in), y(in);
    v[i] = y - x;
  }
  cout << (v.count(v[0]) == v.size() && v[0] > 0 ? v[0] : -1) << endl;
}
