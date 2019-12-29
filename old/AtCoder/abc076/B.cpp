#include "template.hpp"

int main() {
  int n(in), k(in), t = 1;
  for (int i = 0; i < n; ++i) {
    if (t < k) {
      t *= 2;
    } else {
      t += k;
    }
  }
  cout << t << endl;
}
