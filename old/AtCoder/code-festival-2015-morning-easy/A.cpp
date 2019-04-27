#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  for (int i = 0; ; ++i) {
    if (!isSquare(n + i)) continue;
    cout << i << endl;
    return 0;
  }
}
