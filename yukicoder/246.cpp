#include "template.hpp"

int main() {
  int l = 1, h = 1e9 + 1;
  while (l + 1 < h) {
    int m = (l + h) / 2;
    cout << "? " << m << endl;
    int res;
    cin >> res;
    (res == 1 ? l : h) = m;
  }
  cout << l << endl;
}
