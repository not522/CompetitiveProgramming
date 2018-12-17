#include "template.hpp"

int main() {
  int64_t n, k;
  cin >> n >> k;
  if (k % 2) {
    n /= k;
    cout << n * n * n << endl;
  } else {
    auto m = n / k;
    auto l = (n + k / 2) / k;
    cout << m * m * m + l * l * l << endl;
  }
}
