#include "math/circulant_matrix.hpp"
#include "math/pow.hpp"

int main() {
  Vector<int> v(6);
  CirculantMatrix<int> m(6);
  for (int i = 0; i < 6; ++i) v[i] = i + 1;
  m[5] = 1;
  int n;
  cin >> n;
  v = pow(m, n / 5) * v;
  for (int i = 0; i < n % 5; ++i) swap(v[i], v[i + 1]);
  for (int i = 0; i < 6; ++i) cout << v[i];
  cout << endl;
}
