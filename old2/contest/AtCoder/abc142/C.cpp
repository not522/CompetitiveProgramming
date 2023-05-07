#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  Vector<Tuple<int, int>> res;
  for (int i = 0; i < n; ++i) {
    res.emplace_back(a[i], i + 1);
  }
  res.sort();
  res.transform([](Tuple<int, int> t) { return t.get<1>(); }).output(" ");
}
