#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<double> v(n, in);
  v.rsort();
  for (int i = 0; i < n - 1; ++i) {
    v[i] /= pow(2, i + 1);
  }
  v[n - 1] /= pow(2, n - 1);
  cout << v.accumulate() << endl;
}
