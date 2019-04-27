#include "vector.hpp"

int main() {
  Vector<int> a(3, in);
  a.sort();
  cout << (a[0] + a[1] == a[2]) << endl;
}
