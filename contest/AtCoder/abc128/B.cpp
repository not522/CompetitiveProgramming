#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<Tuple<String, int, int>> r(n);
  for (int i = 0; i < n; ++i) {
    r[i].get<0>() = in;
    r[i].get<1>() = -int(in);
    r[i].get<2>() = i + 1;
  }
  r.sort();
  r.transform([](Tuple<String, int, int> i) { return i.get<2>(); }).output();
}
