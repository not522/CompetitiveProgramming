#include "template.hpp"

int main() {
  int s[] = {25, 39, 51, 76, 163, 111, 128, 133, 138};
  set<int> a{0}, b{0};
  for (int i = 0; i < 9; ++i) {
    for (int j : a) b.insert(j + s[i]);
    a = b;
  }
  for (int i : a) {
    b.insert(i + 58);
    b.insert(i + 136);
  }
  for (int i : b) cout << i << endl;
}
