#include "vector.hpp"

int main() {
  int n(in);
  Vector<Tuple<int, int>> p(6);
  for (int i = 0; i < 6; ++i) {
    p[i] = makeTuple(0, i + 1);
  }
  for (int i = 0; i < n; ++i) {
    int l(in);
    ++p[l - 1].get<0>();
  }
  cout << p.max().get<1>() << endl;
}
