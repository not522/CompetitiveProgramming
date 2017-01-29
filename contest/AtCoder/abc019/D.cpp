#include "template.hpp"

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int d;
  cin >> d;
  return d;
}

int main() {
  int n;
  cin >> n;
  int a = 0, r = 0;
  for (int i = 2; i <= n; ++i) {
    int d = query(1, i);
    if (d > r) {
      a = i;
      r = d;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i == a) continue;
    r = max(r, query(a, i));
  }
  cout << "! " << r << endl;
}
