#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int c = 0;
  do {
    do {
      int r = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) ++r;
        if (a[i] < b[i]) --r;
      }
      if (r > 0) ++c;
    } while (next_permutation(b.begin(), b.end()));
  } while (next_permutation(a.begin(), a.end()));
  cout << c / pow(factorial(n), 2);
}
