#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  int a[2]{};
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[mod(x, 2)];
  }
  cout << abs(a[0] - a[1]) << endl;
}
