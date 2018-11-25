#include "template.hpp"

bool in(int n, int x, int y) {
  if (2 * (x + y) < n) return false;
  if (2 * (x + y) > 3 * n) return false;
  if (2 * (x - y) < -n) return false;
  if (2 * (x - y) > n) return false;
  return true;
}

int main() {
  int n, r = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      bool flag = true;
      for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
          if (!in(n, i + x, j + y)) flag = false;
        }
      }
      if (flag) ++r;
    }
  }
  cout << r << endl;
}
