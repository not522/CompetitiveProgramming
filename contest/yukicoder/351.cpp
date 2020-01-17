#include "vector.hpp"

int main() {
  setBoolName("black", "white");
  int h(in), w(in), n(in), x = 0, y = 0;
  Vector<char> s(n);
  Vector<int> k(n);
  read(s, k);
  s.reverse();
  k.reverse();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R' && y == k[i]) {
      x = x ? x - 1 : w - 1;
    }
    if (s[i] == 'C' && x == k[i]) {
      y = y ? y - 1 : h - 1;
    }
  }
  cout << bool((x + y) % 2) << endl;
}
