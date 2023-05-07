#include "math.hpp"

int main() {
  int n(in);
  int a[2]{};
  for (int i = 0; i < n; ++i) {
    int x(in);
    ++a[mod(x, 2)];
  }
  cout << abs(a[0] - a[1]) << endl;
}
