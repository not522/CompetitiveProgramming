#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  auto b = a;
  b.nth_element(1, true);
  for (int i : a) {
    cout << (b[0] == i ? b[1] : b[0]) << endl;
  }
}
