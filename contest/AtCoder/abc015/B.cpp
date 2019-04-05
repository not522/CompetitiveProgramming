#include "math/basic.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  cout << ceil(a.accumulate(), a.count_if([](int i) { return i != 0; }))
       << endl;
}
