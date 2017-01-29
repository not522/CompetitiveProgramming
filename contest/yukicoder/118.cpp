#include "math/mint.hpp"

int main() {
  int n;
  cin >> n;
  long long s[100] = {};
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++s[a - 1];
  }
  Mint res = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = i + 1; j < 100; ++j) {
      for (int k = j + 1; k < 100; ++k) {
        res += s[i] * s[j] * s[k];
      }
    }
  }
  cout << res << endl;
}
