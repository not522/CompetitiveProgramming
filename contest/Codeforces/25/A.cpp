#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), even, odd;
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2) odd.emplace_back(i + 1);
    else even.emplace_back(i + 1);
  }
  cout << (even.size() == 1u ? even[0] : odd[0]) << endl;
}
