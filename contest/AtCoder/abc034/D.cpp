#include "bisection_method.hpp"
#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> w(n), p(n);
  read(w, p);
  auto f = [&](long double q) {
    Vector<long double> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = (q - p[i]) * w[i];
    }
    return v.nth_element(k).subvector(k).accumulate();
  };
  cout << bisectionMethod(f) << endl;
}
