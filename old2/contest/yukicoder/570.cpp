#include "string.hpp"

int main() {
  Vector<Tuple<int, String>> v(3);
  for (int i = 0; i < 3; ++i) {
    v[i].get<0>() = in;
  }
  v[0].get<1>() = "A";
  v[1].get<1>() = "B";
  v[2].get<1>() = "C";
  v.rsort();
  v.transform([](const Tuple<int, String> &a) { return a.get<1>(); }).output();
}
