#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  a.rsort();
  a.unique();
  cout << a[1] << endl;
}
