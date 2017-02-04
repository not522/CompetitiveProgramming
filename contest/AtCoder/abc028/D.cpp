#include "template.hpp"

int main() {
  int64_t n, k;
  cin >> n >> k;
  cout << pow(1.0 / n, 3) * (1 + (n - 1) * 3 + (k - 1) * (n - k) * 6) << endl;
}
