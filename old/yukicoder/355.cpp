#include "vector.hpp"
#include "container/fix_size_set.hpp"

pair<int, int> query(const vector<int>& n) {
  cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
  int x, y;
  cin >> x >> y;
  return make_pair(x, y);
}

int main() {
  map<vector<int>, pair<int, int>> mem;
  for (auto i : FixSizeSet(10, 4)) {
    vector<int> v;
    for (auto j : i) v.emplace_back(j);
    do {
      bool ok = true;
      for (const auto& q : mem) {
        int x = 0, y = 0;
        for (int k = 0; k < 4; ++k) {
          if (q.first[k] == v[k]) ++x;
          else if (in(v, q.first[k])) ++y;
        }
        if (x != q.second.first || y != q.second.second) ok = false;
      }
      if (!ok) continue;
      auto q = query(v);
      if (q.first == 4) return 0;
      mem[v] = q;
    } while (next_permutation(v));
  }
}
