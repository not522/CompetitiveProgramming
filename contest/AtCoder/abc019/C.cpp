#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  for (int &i : a) {
    i /= (i & -i);
  }
  cout << a.sort().unique().size() << endl;
}
