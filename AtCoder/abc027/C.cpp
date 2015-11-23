#include "template.hpp"

int main() {
  long long n;
  cin >> n;
  long long i, k;
  for (i = 0, k = 1; k <= n; ++i) {
    if (i % 2) k *= 2;
    else k = 2 * k + 1;
  }
  if (i % 2 == 0) {
    cout << "Takahashi" << endl;
    return 0;
  }
  for (i = 0, k = 1; k <= n; ++i) {
    if (i % 2) k = 2 * k + 1;
    else k *= 2;
  }
  cout << (i % 2 == 0 ? "Takahashi" : "Aoki") << endl;
}