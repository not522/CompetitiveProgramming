#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  Vector<Tuple<int, int>> res;
  for (int i = 0; i < n; ++i) {
    int j = min_element(a.begin() + i, a.end()) - a.begin();
    if (i != j) {
      res.emplace_back(i, j);
    }
    swap(a[i], a[j]);
  }
  cout << res.size() << endl;
  for (auto i : res) {
    cout << i.get<0>() << " " << i.get<1>() << endl;
  }
  (void)static_cast<int>(in);
}
