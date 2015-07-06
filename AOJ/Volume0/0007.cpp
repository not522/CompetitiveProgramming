#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  int k = 100000;
  for (int i = 0; i < n; ++i) {
    k = ceil(k * 105 / 100, 1000);
  }
  cout << k << endl;
}
