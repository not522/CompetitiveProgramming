#include "template.hpp"

int main() {
  array<int, 13> c{{0}};
  for (int i = 0; i < 5; ++i) {
    int a;
    cin >> a;
    ++c[a - 1];
  }
  if (count(c.begin(), c.end(), 3) && count(c.begin(), c.end(), 2)) cout << "FULL HOUSE" << endl;
  else if (count(c.begin(), c.end(), 3)) cout << "THREE CARD" << endl;
  else if (count(c.begin(), c.end(), 2) == 2) cout << "TWO PAIR" << endl;
  else if (count(c.begin(), c.end(), 2)) cout << "ONE PAIR" << endl;
  else cout << "NO HAND" << endl;
}
