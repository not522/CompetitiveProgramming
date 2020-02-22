#include "vector.hpp"

int main() {
  setBoolName("APPROVED", "DENIED");
  int n(in);
  Vector<int> a(n, in);
  auto f = [](int i) { return i % 2 || i % 3 == 0 || i % 5 == 0; };
  cout << a.all_of(f) << endl;
}
