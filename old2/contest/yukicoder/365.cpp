#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  for (int i : a.reverse()) {
    if (i == n) {
      --n;
    }
  }
  cout << n << endl;
}
