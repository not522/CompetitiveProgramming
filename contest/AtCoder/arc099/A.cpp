#include "math/basic.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  cout << ceil(n - 1, k - 1) << endl;
}
