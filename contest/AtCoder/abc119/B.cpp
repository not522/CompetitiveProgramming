#include "string.hpp"
#include "tuple.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<Tuple<double, String>> x(n, in);
  auto f = [](const Tuple<double, String> &t) {
    return t.get<1>() == "JPY" ? t.get<0>() : t.get<0>() * 380000;
  };
  cout << x.transform(f).accumulate();
}
