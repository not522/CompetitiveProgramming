#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  for (int i = 0; i < n / 2; ++i) a[i] += a[n - i - 1];
  a.resize(n / 2);
  cout << max(a) - min(a) << endl;
}
