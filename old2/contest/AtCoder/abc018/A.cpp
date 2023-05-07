#include "vector.hpp"

int main() {
  Vector<int> a(3, in);
  for (int i : a) {
    cout << a.count_if([i](int n) { return i <= n; }) << endl;
  }
}
