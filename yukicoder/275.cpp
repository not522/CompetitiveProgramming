#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  cout << (a[(n - 1) / 2] + a[n / 2]) / 2.0 << endl;
}
