#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  int n = abs(a - b), r = numeric_limits<int>::max();
  for (int i = 0; i <= 4; ++i) {
    for (int j = 0; j <= 1; ++j) {
      for (int k = -2; k <= 2; ++k) {
        if (i * 10 + j * 5 + k == n) r = min(r, i + j + abs(k));
      }
    }
  }
  cout << r << endl;
}
