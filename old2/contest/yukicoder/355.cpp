#include "container/fix_size_set.hpp"
#include "vector.hpp"

Tuple<int, int> query(const Vector<int> &n) {
  cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
  int x(in), y(in);
  return makeTuple(x, y);
}

int main() {
  Map<Vector<int>, Tuple<int, int>> mem;
  for (auto i : fixSizeSet(10, 4)) {
    Vector<int> v;
    for (auto j : i) {
      v.emplace_back(j);
    }
    do {
      bool ok = true;
      for (const auto &q : mem) {
        int x = 0, y = 0;
        for (int k = 0; k < 4; ++k) {
          if (q.first[k] == v[k]) {
            ++x;
          } else if (v.contains(q.first[k])) {
            ++y;
          }
        }
        if (x != q.second.get<0>() || y != q.second.get<1>()) {
          ok = false;
        }
      }
      if (!ok) {
        continue;
      }
      auto q = query(v);
      if (q.get<0>() == 4) {
        return 0;
      }
      mem[v] = q;
    } while (v.next_permutation());
  }
}
