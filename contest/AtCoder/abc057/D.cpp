#include "math/combination.hpp"
#include "vector.hpp"

int main() {
  int n(in), a(in), b(in);
  Vector<int64_t> v(n, in);
  v.rsort();
  int k = 0;
  for (int i = a - 1; i >= 0 && v[i] == v[a - 1]; --i) {
    ++k;
  }
  int t = v.countAll()[v[a - 1]];
  int64_t c = 0;
  Combination<int64_t> comb;
  if (v[0] == v[a - 1]) {
    for (int i = a; i <= min(b, t); ++i) {
      c += comb.combination(t, i);
    }
  } else {
    c = comb.combination(t, k);
  }
  cout << double(v.subvector(0, a).accumulate()) / a << endl;
  cout << c << endl;
}
