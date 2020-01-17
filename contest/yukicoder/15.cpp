#include "container/power_set.hpp"
#include "unordered_map.hpp"
#include "vector.hpp"

Vector<Tuple<int, Vector<int>>> solve(const Vector<int> &p) {
  Vector<Tuple<int, Vector<int>>> res;
  for (auto t : powerSet(p.size())) {
    int sum = 0;
    Vector<int> v;
    for (auto i : t) {
      sum += p[int(i)];
      v.emplace_back(i);
    }
    res.emplace_back(sum, v);
  }
  return res;
}

int main() {
  int n(in), s(in);
  Vector<int> p(n / 2, in), q(n - n / 2, in);
  UnorderedMap<int, Vector<Vector<int>>> a;
  for (const auto &i : solve(p)) {
    a[i.get<0>()].emplace_back(i.get<1>());
  }
  Vector<Vector<int>> res;
  for (const auto &i : solve(q)) {
    for (const auto &u : a[s - i.get<0>()]) {
      Vector<int> vv;
      for (int j : u) {
        vv.emplace_back(j + 1);
      }
      for (int j : i.get<1>()) {
        vv.emplace_back(j + n / 2 + 1);
      }
      res.emplace_back(vv);
    }
  }
  res.sort();
  for (const auto &i : res) {
    i.output(" ");
  }
}
