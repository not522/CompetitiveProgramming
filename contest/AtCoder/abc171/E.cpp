#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  int x = a.accumulate(0, std::bit_xor<int>());
  a.transform([&](int k) { return k ^ x; }).output(" ");
}
