#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  sort(a.begin(), a.end());
  cout << (a[(n - 1) / 2] + a[n / 2]) / 2.0 << endl;
}
