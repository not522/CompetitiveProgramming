#include "vector.hpp"

int main() {
  int64_t n(in), k(in);
  Vector<Tuple<int64_t, int64_t>> p(n, in);
  p.sort();
  for (auto i : p) {
    k -= i.get<1>();
    if (k <= 0) {
      cout << i.get<0>() << endl;
      return 0;
    }
  }
}
