#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 1; i <= n;) {
    bool a = false, b = false, c = false;
    for (int k = 1; k <= i; k *= 10) {
      int x = i / k % 10;
      if (x == 3) {
        a = true;
      } else if (x == 5) {
        b = true;
      } else if (x == 7) {
        c = true;
      } else {
        i = i / k * k + k;
        goto next;
      }
    }
    if (a && b && c) ++res;
    ++i;
  next:;
  }
  cout << res << endl;
}
