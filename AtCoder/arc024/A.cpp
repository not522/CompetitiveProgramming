#include "container/multiset.hpp"

int main() {
  int l, r;
  cin >> l >> r;
  MultiSet<int> a, b;
  for (int i = 0; i < l; ++i) {
    int x;
    cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < r; ++i) {
    int x;
    cin >> x;
    b.insert(x);
  }
  cout << (a * b).size() << endl;
}
