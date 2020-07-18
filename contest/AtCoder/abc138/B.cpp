#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  cout << 1 / a.transform([](int i) { return 1.0 / i; }).accumulate() << endl;
}
