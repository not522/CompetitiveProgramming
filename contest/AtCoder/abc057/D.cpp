#include "vector.hpp"
#include "math/combination.hpp"

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int64_t> v(n);
  cin >> v;
  rsort(v);
  int k = 0;
  for (int i = a - 1; i >= 0 && v[i] == v[a - 1]; --i) ++k;
  int t = count_kinds(v)[v[a - 1]];
  int64_t c = 0;
  Combination<int64_t> comb;
  if (v[0] == v[a - 1]) {
    for (int i = a; i <= min(b, t); ++i) c += comb.combination(t, i);
  } else {
    c = comb.combination(t, k);
  }
  cout << double(accumulate(subvector(v, 0, a))) / a << endl;
  cout << c << endl;
}
