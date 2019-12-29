#include "vector.hpp"

int main() {
  int n(in);
  Vector<Tuple<int, int>> a;
  for (int i = 0; i < n; ++i) {
    int h(in);
    a.emplace_back(h, i + 1);
  }
  a.rsort();
  for (auto i : a) {
    cout << i.get<1>() << endl;
  }
}
