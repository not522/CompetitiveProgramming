#include "template.hpp"

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  return in;
}

int main() {
  int n(in);
  int a = 0, r = 0;
  for (int i = 2; i <= n; ++i) {
    int d = query(1, i);
    if (d > r) {
      a = i;
      r = d;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i != a) {
      chmax(r, query(a, i));
    }
  }
  cout << "! " << r << endl;
}
