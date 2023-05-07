#include "map.hpp"

int main() {
  int q(in);
  Map<int64_t, int64_t> m;
  for (int i = 0; i < q; ++i) {
    int p(in);
    if (p == 0) {
      int64_t k(in), v(in);
      m[k] = v;
    } else {
      int64_t k(in);
      cout << m[k] << endl;
    }
  }
}
