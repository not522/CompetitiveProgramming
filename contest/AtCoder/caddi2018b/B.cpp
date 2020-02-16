#include "vector.hpp"

int main() {
  int n(in), h(in), w(in);
  Vector<Tuple<int, int>> a(n, in);
  auto f = [&](Tuple<int, int> i) {
    return i.get<0>() >= h && i.get<1>() >= w;
  };
  cout << a.count_if(f) << endl;
}
